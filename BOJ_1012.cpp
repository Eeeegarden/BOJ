#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int M,N; // M=col , N=row
    int K;
    int x,y; // x==M , y==N
    queue<pair<int,int>> Q;

    cin >> T;

    for(int q=0; q<T; q++){
        int board[51][51]={0};
        int vis[51][51]={0};
        int warm=0;
        cin >> M >> N >> K ;
        for(int i=0; i<K; i++){
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(board[i][j] == 1 && vis[i][j] != 1) {
                    Q.push({i,j});
                    warm++;
                }
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                        if(vis[nx][ny] != 0 || board[nx][ny]==0) continue;
                        vis[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout << warm << '\n' ;
    }
}    
