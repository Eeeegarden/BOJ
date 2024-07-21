//푸는중

#include <bits/stdc++.h>
using namespace std;

int board[5][5][5]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int dz[2]={0,1};
int ans=INT_MAX;
queue<tuple<int,int,int>> Q;


void rotate(int Z){
    int tmp[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            tmp[i][j] = board[Z][5-j-1][i];
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            board[Z][i][j] = tmp[i][j];
        }
    }
}

// 모든경우의수 계산하기
// 5*5*5
// 000
// 5*4*4*4*4*4
// 1초에 10억번계산가능 
// 각 판마다 rotate 4번씩 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin >> board[i][j][k];
            }
        }
    }

    // 첫 좌표 넣어야하는데 들어갈수 있어야 큐에 넣을 수 있는데
    // 회전해서 들어가는경우 , 판 순서 고려해서 생각해야하는데..흠
    // 입구가 될 수 있는 좌표 모두 넣기?
    // 아니면 순서정해서
    if(board[0][0][0]==1)Q.push({0,0,0});

    // 판 순서 , 판 회전 고려해야함
    while(!Q.empty()){
        int vis[5][5][5]={0,};
        auto cur = Q.front(); Q.pop();
        int curX,curY,curZ;
        tie(curX, curY, curZ) = cur;
        for(int dirz=0; dirz<2; dirz++){
            for(int dir=0; dir<4; dir++){
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                int nz = curZ + dz[dirz];
                if(nx<0 || nx>=5 || ny<0 || ny>=5 || nz>=5)continue;
                if(vis[nz][nx][ny]!=0)continue;
                if(board[nz][nx][ny]==1){
                    Q.push({nz,nx,ny});
                    vis[nz][nx][ny]=vis[curZ][curX][curY]+1;
                }
                if(vis[5][5][5]!=0 && vis[5][5][5]<ans)ans=vis[5][5][5];
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << board[0][i][j];
        }
        cout << '\n';
    }
}
