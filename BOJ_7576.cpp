#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int box[1002][1002];
int day[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; // n=col , m=row
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int fin_d = 0;
    int plus_d = 0;
    queue<pair<int,int>> Q;

    fill(day[0],day[1002], -1);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) {
                Q.push({i,j});
                day[i][j]=0;
            }
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if((nx<0 || nx>=m) || (ny<0 || ny>=n)) continue;
            if(day[nx][ny]>=0)continue;
            if(box[nx][ny] == -1) continue;
            Q.push({nx,ny});
            day[nx][ny]=day[cur.X][cur.Y]+1;
            if(fin_d<=day[nx][ny])fin_d=day[nx][ny];
        };
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(day[i][j]==-1 && box[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << fin_d ; 
}