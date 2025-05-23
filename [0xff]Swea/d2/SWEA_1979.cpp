#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,K,T;
int board[17][17];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        int ans=0;
        cin >> N >> K;
        // 방향도 저장해야함
        int vis[4][17][17]={0,};
        queue<pair<int,int>> Q;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> board[i][j];
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j]!=0){
                    for(int dir=0; dir<4; dir++){
                        int num=0;
                        if(vis[dir][i][j]!=0)continue;
                        Q.push({i,j});
                        vis[dir][i][j]=1;
                        while(!Q.empty()){
                            auto cur = Q.front(); Q.pop();
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx<0 || ny<0 || nx>=N || ny>=N)continue;
                            if(vis[dir][nx][ny]!=0)continue;
                            if(board[nx][ny]==0)continue;
                            Q.push({nx,ny});
                            vis[dir][nx][ny]=vis[dir][cur.X][cur.Y]+1;
                            num = vis[dir][nx][ny];
                        }
                        if(num==K)ans++;
                    }
                }
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}