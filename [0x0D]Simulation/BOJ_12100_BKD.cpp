// BKD풀이
// 기울이는 함수, 보드 돌리는 함수

#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
int board2[22][22];
int ans;

// board2 시계방향 90도 회전
void rotate(){
    int tmp[22][22];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tmp[i][j]=board2[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board2[i][j]=tmp[N-1-j][i];
        }
    }
}

// 한쪽으로 기울이는 함수
// O(N)으로 처리가능 ㄷㄷ
// idx에 값이 있는지 없는지에 따라 처리가능
void tilt(int dir){
    while(dir--) rotate();
    for(int i=0; i<N; i++){
        int tilted[22]={0,};
        int idx=0;
        for(int j=0; j<N; j++){
            if(board2[i][j]==0)continue;
            if(tilted[idx]==0) tilted[idx]=board2[i][j];
            else if(tilted[idx] == board2[i][j]) tilted[idx++]*=2;
            else tilted[++idx]=board2[i][j];
        }
        for(int j=0; j<N; j++) board2[i][j] = tilted[j];
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }

    // 5번 기울이는 경우의수 4의5제곱
    for(int tmp=0; tmp<1024; tmp++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                board2[i][j] = board[i][j];
            }
        }
        int brute = tmp;
        for(int i=0; i<5; i++){
            int dir=brute%4;
            brute/=4;
            tilt(dir);
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ans=max(ans,board2[i][j]);
            }
        }
    }
    
    cout << ans;
}