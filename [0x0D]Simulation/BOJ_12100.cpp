// 직관적으로 상하좌우 움직이는 풀이
// 나중에 roate,tilt로도 풀어보기

// 입력하는 보드와 만들어지는 보드 생각잘하기(row,col) = 상하반전
// 답지 참고 https://velog.io/@y00913/%EB%B0%B1%EC%A4%80-12100-2045-Easy-C

#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
char dirst[5];
int ans=0;


void prt(){
    
    // for(int i=0; i<5; i++){
    //     // cout << dirst[i];
    // }
    // cout << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            // cout << board[i][j] << ' ';
            ans=max(board[i][j],ans);
        }
        // cout << '\n';
    }
}

// 윗방향
void nmv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int j=0; j<N; j++){
        while(1){
            bool tf = false;

            for(int i=1; i<N; i++){
                if(board2[i][j]==0)continue;

                if(board2[i-1][j]==0){
                    board2[i-1][j] = board2[i][j];
                    board2[i][j] = 0;
                    tf = true;

                    if(comb[i][j]){
                        comb[i-1][j] = true;
                        comb[i][j] = false;
                    }
                }
                else if(board2[i-1][j] == board2[i][j] && !comb[i-1][j] && !comb[i][j]){
                    board2[i-1][j]*=2;
                    board2[i][j]=0;
                    tf=true;
                    comb[i-1][j]=true;
                }
            }
            if(!tf)break;
        } 
    }
}

// 아래방향
void smv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int j=0; j<N; j++){
        while(1){
            bool tf = false;
            
            for(int i= N-2; i>=0; i--){
                if(board2[i][j]==0) continue;
                
                // 0이면 밀기
                if (board2[i + 1][j] == 0) {
                    board2[i + 1][j] = board2[i][j];
                    board2[i][j] = 0;
                    tf = true;
                    // 밀때 comb도 같이밀기
                    if (comb[i][j]) {
                        comb[i + 1][j] = true;
                        comb[i][j] = false;
                    }
                }
                // 합쳐지는 숫자면 합치기
                else if (board2[i + 1][j] == board2[i][j] && !comb[i+1][j] && !comb[i][j]) {
                    board2[i + 1][j] += board2[i][j];
                    board2[i][j] = 0;
                    tf = true;
                    comb[i + 1][j] = true;
                }
            }
            // 조건문 못들어가면 탈출
            if (!tf) break;
        }
    }
}

// 서쪽 방향
void wmv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int i=0; i<N; i++){
        while(1){
            bool tf = false;
            for(int j=1; j<N; j++){
                if(board2[i][j]==0)continue;
                
                if(board2[i][j-1]==0){
                    board2[i][j-1]=board2[i][j];
                    board2[i][j]=0;
                    tf=true;
                    if(comb[i][j]){
                        comb[i][j-1]=true;
                        comb[i][j]=false;
                    }
                }
                else if(board2[i][j-1]==board2[i][j] && !comb[i][j] && !comb[i][j-1]){
                    board2[i][j-1] *=2;
                    board2[i][j]=0;
                    tf = true;
                    comb[i][j-1]=true;
                }
            }
            if(!tf)break;
        }
    }
}

// 동쪽방향
void emv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int i=0; i<N; i++){
        while(1){
            bool tf = false;
            for(int j= N-2; j>=0; j--){
                if(board[i][j]==0)continue;

                if(board[i][j+1]==0){
                    board[i][j+1]=board[i][j];
                    board[i][j]=0;
                    tf=true;
                    if(comb[i][j]){
                        comb[i][j+1]=true;
                        comb[i][j]=false;
                    }
                }
                else if(board[i][j+1] == board[i][j] && !comb[i][j] && !comb[i][j+1]){
                    board[i][j+1] *=2;
                    board[i][j]=0;
                    tf=true;
                    comb[i][j+1]=true;
                }
            }
            if(!tf)break;
        }
    }
}


void DFS(int cnt,int board2[][22]){
    if(cnt==5){
        prt();
        return;
    }
    int temp[22][22];
    memcpy(temp, board2, sizeof(temp));
    for(int i=0; i<4; i++){
        switch(i){
            case 0:
                dirst[cnt]='w';
                wmv(board2);
                break;
            case 1:
                dirst[cnt]='e';
                emv(board2);
                break;
            case 2:
                dirst[cnt]='n';
                nmv(board2);
                break;
            case 3:
                dirst[cnt]='s';
                smv(board2);
                break;
        }
    DFS(cnt+1,board2);
    memcpy(board2, temp, sizeof(temp));
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

    DFS(0,board);


    cout << ans;

}