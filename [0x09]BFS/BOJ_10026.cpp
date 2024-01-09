#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

// 각각 경우에따라 두번 계산했는데 좀더 컴팩트한 방법 ??
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char board[102][102];
    char n_col;
    int vis[102][102];
    int N;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int nw_count=0;
    int w_count=0;
    queue<pair<int,int>> Q;

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j] ;
        }
    }
    
    //색맹이 아닌경우
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(vis[i][j] == 0) {
                Q.push({i,j});
                n_col=board[i][j];
                nw_count++;
            }
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    if(vis[nx][ny] != 0 || n_col!=board[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }  
            }
        }
    }
    // 색맹인경우
    fill(vis[0],vis[102],0);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(vis[i][j] == 0) {
                Q.push({i,j});
                n_col=board[i][j];
                w_count++;
            }
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    if(vis[nx][ny] != 0) continue;
                    if(n_col != 'B' && board[nx][ny] == 'B') continue;
                    if(n_col == 'B' && n_col != board[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }  
            }
        }
    }
    cout << nw_count << ' ' << w_count;
}