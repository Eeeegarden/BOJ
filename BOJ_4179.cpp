#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

//배열의 크기가 너무 크다면 전역변수로 선언 (heap메모리 초과해서그럼)
string maze[1002];
pair<int,int> dis[1002][1002];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int>> Q;
int R;
int C;
int ans=1005;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C ; // R=row , C=col

    for(int i=0; i<R; i++){
        cin >> maze[i] ;
    }

// 지훈 거리 BFS 계산
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(maze[i][j] == 'J') Q.push({i,j});
            if(maze[i][j] == '.') dis[i][j].X=-1;
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 || nx>=R || ny<0 || ny>=C ) continue;
            if(dis[nx][ny].X>=0) continue;
            dis[nx][ny].X=dis[cur.X][cur.Y].X+1;
            Q.push({nx,ny});
        }
    }

// 불 거리 BFS계산
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(maze[i][j] == 'F') Q.push({i,j});
            if(maze[i][j] == '.') dis[i][j].Y=-1;
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 || nx>=R || ny<0 || ny>=C ) continue;
            if(dis[nx][ny].Y>=0) continue;
            dis[nx][ny].Y=dis[cur.X][cur.Y].Y+1;
            Q.push({nx,ny});
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            // 지훈이가 탈출하는경우 if문 진입
            if((dis[i][j].X>0 && (i==R-1 || j==C-1 || j==0 || i==0)) || (maze[i][j]=='J' && (i==0 || j==0 || i==R-1 || j==C-1)) ) {
                //불이 갇혀있는경우
                if(dis[i][j].Y<=0) {
                    ans=dis[i][j].X;
                }
                // 불이 갇혀있지않고 불이 지훈이보다 빠를경우 예외처리
                else if(dis[i][j].Y>0 && dis[i][j].X>=dis[i][j].Y) continue;
                // 정상적으로 탈출이 가능한경우
                else {
                    if(ans>dis[i][j].X) ans=dis[i][j].X;
                }
            }
        }
    }
    if(ans==1005) cout << "IMPOSSIBLE" ;
    else cout << ans+1;
}



