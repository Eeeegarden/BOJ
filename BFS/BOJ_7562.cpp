#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[302][302];
int vis[302][302];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int l;
    int dx[8]={2,2,1,1,-1,-1,-2,-2};
    int dy[8]={-1,1,-2,2,-2,2,-1,1};
    pair<int,int> b_loc;
    pair<int,int> o_loc;
    queue<pair<int,int>> Q;
    
    cin >> t;

    for(int i=0; i<t; i++){
        fill(vis[0],vis[300],-1);
        cin >> l;
        cin >> b_loc.X >> b_loc.Y;
        vis[b_loc.X][b_loc.Y]=0;
        Q.push({b_loc.X,b_loc.Y});
        cin >> o_loc.X >> o_loc.Y;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int i=0; i<8; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                // 좌표이동이 아니라 칸 이동 주의
                if(nx<0 || ny<0 || nx>l-1 || ny>l-1) continue;
                if(vis[nx][ny]!=-1) continue;
                vis[nx][ny]=vis[cur.X][cur.Y]+1;
                Q.push({nx,ny});
            }
        }
        cout << vis[o_loc.X][o_loc.Y] << '\n';
    }
}
