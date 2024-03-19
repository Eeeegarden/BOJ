// 반례 찾는중..

#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
int ans=0;


void prt(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 윗방향
void nmv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int j=0; j<N; j++){
        for(int i=1; i<N; i++){
            if(board2[i][j]!=0){
                for(int ci=i; ci>0; ci--){
                    // 블록에 숫자가 있을때
                    if(board2[ci-1][j]!=0){
                        // 블록 숫자가 같고 합쳐진 블록이 아니라면 합침
                        if(board2[ci-1][j]==board2[ci][j] && comb[ci-1][j]==0){
                            board2[ci-1][j]*=2;
                            board2[ci][j]=0;
                            comb[ci-1][j]=true;
                            if(board2[ci-1][j]>=ans)ans=board2[ci-1][j];
                        }
                    }
                    // 블록에 숫자가 없으면 방향으로 이동
                    else {
                        board2[ci-1][j]=board2[ci][j];
                        board2[ci][j]=0;
                        if(board2[ci-1][j]>=ans)ans=board2[ci-1][j];
                    }
                }
            }
        }
    }
}

// 아래방향
void smv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int j=0; j<N; j++){
        for(int i=N-1; i>0; i--){
            if(board2[i][j]!=0){
                for(int ci=i; ci<N-1; ci++){
                    // 블록에 숫자가 있을때
                    if(board2[ci+1][j]!=0){
                        // 블록 숫자가 같고 합쳐진 블록이 아니라면 합침
                        if(board2[ci+1][j]==board2[ci][j] && comb[ci+1][j]==0){
                            board2[ci+1][j]*=2;
                            board2[ci][j]=0;
                            comb[ci+1][j]=true;
                            if(board2[ci+1][j]>=ans)ans=board2[ci+1][j];
                        }
                    }
                    // 블록에 숫자가 없으면 방향으로 이동
                    else {
                        board2[ci+1][j]=board2[ci][j];
                        board2[ci][j]=0;
                        if(board2[ci+1][j]>=ans)ans=board2[ci+1][j];
                    }
                }
            }
        }
    }
}

// 서쪽 방향
void wmv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int i=0; i<N; i++){
        for(int j=1; j<N; j++){
            if(board2[i][j]!=0){
                for(int cj=j; cj>0; cj--){
                    if(board2[i][cj-1]!=0){
                        if(board2[i][cj-1]==board2[i][cj] && comb[i][cj-1]==0){
                            board2[i][cj-1]*=2;
                            board2[i][cj]=0;
                            comb[i][cj-1]=true;
                            if(board2[i][cj-1]>=ans)ans=board2[i][cj-1];
                        }
                    }
                    else{
                        board2[i][cj-1]=board2[i][cj];
                        board2[i][cj]=0;
                        if(board2[i][cj-1]>=ans)ans=board2[i][cj-1];
                    }
                }
            }
        }
    }
}

// 동쪽방향
void emv(int board2[][22]){
    bool comb[22][22]={0,};
    for(int i=0; i<N; i++){
        for(int j=N-1; j>=0; j--){
            if(board2[i][j]!=0){
                for(int cj=j; cj<N-1; cj++){
                    if(board2[i][cj+1]!=0){
                        if(board2[i][cj+1]==board2[i][cj] && comb[i][cj+1]==0){
                            board2[i][cj+1]*=2;
                            board2[i][cj]=0;
                            comb[i][cj+1]=true;
                            if(board2[i][cj+1]>=ans)ans=board2[i][cj+1];
                        }
                    }
                    else{
                        board2[i][cj+1]=board2[i][cj];
                        board2[i][cj]=0;
                        if(board2[i][cj+1]>=ans)ans=board2[i][cj+1];
                    }
                }
            }
        }
    }
}


void DFS(int cnt,int board2[][22]){
    if(cnt==5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << board2[i][j] << ' ';
                if(board2[i][j]>=ans)ans=board2[i][j];
            }
            cout << '\n';
        }
        return;
    }
    int temp[22][22];
    memcpy(temp, board2, sizeof(temp));
    for(int i=0; i<4; i++){
        switch(i){
            case 0:
                wmv(board2);
                break;
            case 1:
                emv(board2);
                break;
            case 2:
                nmv(board2);
                break;
            case 3:
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