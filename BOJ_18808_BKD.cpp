// Authored by : BaaaaaaaaaaarkingDog
// 깔끔한 풀이방법

#include <bits/stdc++.h>
using namespace std;

int N,M,K;
int r,c;
int ans=0;
int m[42][42]={0,};
int s[12][12]={0,};


bool pastable(int x,int y){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(m[x+i][y+j]==1 && s[i][j]==1)return false;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(s[i][j]==1)m[x+i][y+j]=1;
        }
    }
    return true;
}

void rotate(){
    int temp[12][12]={0,};

    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            temp[i][j]=s[r-1-j][i];
        }
    }
    copy(temp[0],temp[0]+300,s[0]);
    swap(r,c);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    while(K--){
        bool is_paste=false;
        cin >> r >> c;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> s[i][j];
            }
        }

        for(int rot=0; rot<4; rot++){
            for(int i=0; i+r<=N; i++){
                if(is_paste)break;
                for(int j=0; j+c<=M; j++){
                    if(is_paste)break;
                    if(pastable(i,j)){
                        is_paste=true;
                        break;
                    }
                }
            }
            if(is_paste)break;
            rotate();
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << m[i][j] << ' ';
            if(m[i][j]==1)ans++;
        }
        cout << '\n';
    }
    cout << ans;
}