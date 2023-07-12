#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[502][502]={0,};
    int vis[502][502]={0,};
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int  m;
    int n;
    int paint_size=0;
    int max_size=0;
    int paint_count=0;
    queue<pair<int,int>> Q;

    cin >>  m >> n;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if((vis[i][j]==0 && board[i][j]==1)) {
                paint_count++;
                // 그림이 1개일때 반례처리
                if(max_size==0) max_size=1;
                vis[i][j]==1;
                Q.push({i,j});
            }
            paint_size=0;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    if(paint_size>=max_size)max_size=paint_size;
                    int nx=cur.X+dx[dir];
                    int ny=cur.Y+dy[dir];
                    if((nx<0 || nx>m)||(ny<0 || ny>n))continue;
                    if(vis[nx][ny]==1||board[nx][ny]==0)continue;
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                    paint_size++;
                }
            }
        }
    }

    cout << paint_count << '\n' << max_size;

}