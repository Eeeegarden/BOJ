푸는중..
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[202][202];
int vis[31][202][202];
// 시계방향 -> 상하좌우 순서
int dx[12]={1,2,2,1,-1,-2,-2,-1,1,-1,0,0};
int dy[12]={-2,-1,1,2,2,1,-1,-2,0,0,-1,1};
int k;
int k_time=0;
bool hor_mov =0;
int w,h;
queue<tuple<int,int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cin >> w >> h;

    for(int q=0; q<k; q++){
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> board[i][j];
                if(board[i][j]==1)vis[q][i][j]=-1;
                else vis[q][i][j]=0;
            }
        }
    }
    
    Q.push({0,0,0});
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<12; dir++){
            int nz = get<0>(cur);
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
            if(board[nx][ny]==1 || vis[k_time][nx][ny]>0) continue;
            if(k_time>=k && dir<8) continue;
            if(dir<8){
                k_time++;
                vis[nz+k_time][nx][ny]=vis[nz+k_time][get<1>(cur)][get<2>(cur)]+1;
                Q.push({nz+k_time,nx,ny});
            }
            else if(dir>=8){
                vis[nz][nx][ny]=vis[nz][get<1>(cur)][get<2>(cur)]+1;
                Q.push({nz,nx,ny});
            }
        }
    }


    cout << vis[0][h-1][w-1];

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << vis[0][h-1][w-1] << ' ';
        }
        cout << '\n';
    }


    if(vis[k_time][h-1][w-1]==0)cout << "-1";
    else cout << vis[k_time][h-1][w-1];


}
