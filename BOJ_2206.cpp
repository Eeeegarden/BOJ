// 수정중...

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int vis[1002][1002];
int vis2[1002][1002];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n,m;
bool wall=0;
queue<pair<int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m ; // n=row m=col
    for(int i=0; i<n; i++){
        fill(vis[i],vis[i]+m,-1);
        cin >> board[i];
    }
    Q.push({0,0});
    vis[0][0]=1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || ny<0 || nx>n || ny>m) continue;
            if(board[nx][ny]=='1'){
                board[nx][ny]='0';
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        vis2[i][m]=vis[i][m];
                    }
                }
                queue<pair<int,int>> Q2;
                Q2.push({nx,ny});
                vis2[nx][ny]=vis2[cur.X][cur.Y]+1;
                while(!Q2.empty()){
                    auto cur2 = Q2.front(); Q2.pop();
                    for(int dir2=0; dir2<4; dir2++){
                        int nx2 = cur2.X + dx[dir2];
                        int ny2 = cur2.Y + dy[dir2];
                        if(nx2<0 || ny2<0 || nx2>n || ny2>m) continue;
                        if(vis2[nx2][ny2]>0 || board[nx2][ny2] == '1') continue;
                        Q2.push({nx2,ny2});
                        vis2[nx2][ny2]=vis2[cur2.X][cur2.Y]+1;
                    }
                }
                board[nx][ny]='1';
                if(vis[nx][ny]!=-1 && vis[nx][ny]>vis2[nx][ny])vis[nx][ny]=vis2[nx][ny];
                // if(vis[n-1][m-1]==-1) vis[n-1][m-1]=vis2[n-1][m-1];
                // else if(vis[n-1][m-1]!=-1 && vis2[n-1][m-1]<vis[n-1][m-1]) vis[n-1][m-1]=vis2[n-1][m-1];
                // else continue;
            }
            if(vis[nx][ny]>0) continue;
            Q.push({nx,ny});
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
        }
    }

    cout << vis[n-1][m-1] << '\n' << '\n';


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << vis2[i][j] << ' ' ;
        }
        cout << '\n';
    }
            
}