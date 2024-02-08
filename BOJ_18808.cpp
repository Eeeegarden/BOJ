// 푸는중


// 현재 로직 
/*
입력->체크-> O -> 삽입
             X -> 평이 -> O 
                       -> X -> 90회전 -> O
                                      -> X -> 180,270 ->
                                                      -> X -> 건너뜀

시간복잡도 걸림
예외처리 빡세게 해도 걸릴듯?

*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m[50][50]={0,}; // 노트북
int N,M,K;
int flag=0;

void check_s(int x,int y,int hei,int len,int s[50][50],int s_num){
    int m2[50][50];
    int cnt=0;
    copy(m[0],m[0]+2500,m2[0]);
    for(int i=0; i<hei; i++){
        for(int j=0; j<len; j++){
            if(m[x+i][y+j]==1 && s[i][j]==1) return;
            if(m[x+i][y+j]==0 && s[i][j]==0) continue;
            if(m[x+i][y+j]==0 && s[i][j]==1){
                cnt++;
                m2[x+i][y+j]=1;
            }
            if(cnt==s_num){
                copy(m2[0],m2[0]+2500,m[0]);
                for(int q=0; q<N; q++){
                    for(int w=0; w<M; w++){
                        cout << m[q][w] << ' ';
                    }
                    cout << '\n';
                }
                flag=1;
                return;
            }
        }
    }
    return;
}

void quest(int h,int l,int s[50][50],int s_num){
    for(int j=0; j<N; j++){
        for(int q=0; q<M; q++){
            if(j+h>N || q+l>M) continue;
            check_s(j,q,h,l,s,s_num);
            if(flag==1)return;
        }
    }
    flag=0;
    return;
}

void rotate_s(int h,int l,int s[50][50],int s_num){
    int tmp_arr[50][50]={0,};
    for(int i=0; i<l; i++){
        for(int j=0; j<h; j++){
            // 90도 회전.
            tmp_arr[i][j]=s[h-1-j][i];
            
        }
    }
    copy(tmp_arr[0],tmp_arr[0]+2500,s[0]);
    return;
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << s[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

}

// 안들어간다면 회전시키기 flag로 quest가 실행됐는지 파악가능
void insert_s(int h,int l,int s[50][50],int s_num){
    flag=0;
    quest(h,l,s,s_num);
    if(flag==0){
        for(int num=0; num<4 && flag==0; num++){
            int tmp;
            rotate_s(h,l,s,s_num);
            tmp=h;
            h=l;
            l=tmp;
            quest(h,l,s,s_num);
        }
        return;
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    for(int i=0; i<K; i++){
        int hei,len;
        int s_num=0;
        int s[50][50]={0,}; // 스티커
        cin >> hei >> len;
        for(int j=0; j<hei; j++){
            for(int q=0; q<len; q++){
                cin >> s[j][q];
                if(s[j][q]==1)s_num++;
            }
        }
        cout << "---try:" << i << "-------" << '\n';
        insert_s(hei,len,s,s_num);
    }
}