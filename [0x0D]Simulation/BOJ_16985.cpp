//푸는중

#include <bits/stdc++.h>
using namespace std;
#define X second
#define Y third
#define Z first

int board[5][5][5]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int dz[2]={0,1};
queue<pair<int,pair<int,int>>> Q;



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

    if(board[0][0][0]==1){
        Q.push({0,0,0});
        vis[0][0][0]=1;
    }
    // rotate해봐야함
    else 

    while(!Q.empty()){
        int vis[5][5][5]={0,};
        auto cur = Q.front(); Q.pop();
        for(int dirz=0; dirz<2; dirz++){
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                int nz = cur.Z + dz[dirz];
                if(nx<0 || nx>=5 || ny<0 || ny>=5 || nz>=5)continue;
                if(vis[nz][nx][ny]!=0)continue;
                if(board[nz][nx][ny]==1)
                    Q.push({nz,nx,ny});
                    vis[nz][nx][ny]++;
                }
            }
        }
    }

    


    




    rotate(0);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << board[0][i][j];
        }
        cout << '\n';
    }
}
