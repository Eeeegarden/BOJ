#include <bits/stdc++.h>
using namespace std;

int T;
int board[10][10];

void tilt(int N){
    int temp[10][10];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = board[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i][j] = temp[N-j-1][i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        int N;
        int p_board[50][50]={0,};
        cin >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> board[i][j];
            }
        }
        
        // 90도씩 돌리고 p_board에 저장
        for(int k=0; k<3; k++){
            tilt(N);
            for(int i=0; i<N; i++){
                for(int j=k*N; j<N*3; j++){
                    p_board[i][j] = board[i][j%N];
                }
            }
        }
        cout << '#' << tc << '\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<N*3; j++){
                if(j!=0 && j%N==0)cout << ' ';
                cout << p_board[i][j];
            }
            cout << '\n';
        }
    }
}