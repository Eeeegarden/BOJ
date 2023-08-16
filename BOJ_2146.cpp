// 예외처리 빡세게 안하면 메모리초과뜸..
// 방문했던곳, 최소 브릿지보다 길면 불필요한 방문 -> 예외처리
// 직관적인 풀이 O(N^4)에 풀이가능 ( N = 100 이라 통과가능 )

// 시작점 하나하나 계산하는것이 아닌 섬의 모든 시작점을 동시에 BFS 돌리면
// O(N^2)에 풀이가능 (https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/2146_1.cpp)
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int land[102][102];
int vis[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n;
int land_num=0;
int min_bri=-1;
queue<pair<int,int>> Q;

void initvis(){
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(land[i][j]!=1)vis[i][j]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> land[i][j];
        }
    }

    // 섬번호를 vis에 음수로 표시
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(land[i][j]==1 && vis[i][j]==0) {
                Q.push({i,j});
                land_num--;                    
                vis[i][j]=land_num;
            }
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    if(land[nx][ny]==0 || vis[nx][ny]!=0) continue;
                    vis[nx][ny]=land_num;
                    Q.push({nx,ny});
                }
            }    
        }
    }

    // BFS
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cur_land=0;
            // 시작점이 될 수 있으면 큐에 push
            if(land[i][j]==1){
                for(int dir=0; dir<4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    if(land[nx][ny]==1)continue;
                    initvis();
                    Q.push({i,j});
                    cur_land=vis[i][j];
                    break;
                }
            }
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    if(land[nx][ny]==0 && vis[nx][ny]!=0) continue;
                    if(land[nx][ny]==1 && vis[nx][ny]==cur_land) continue;
                    if(min_bri!=-1 && vis[cur.X][cur.Y]+1>min_bri) continue;
                    if(vis[nx][ny]<0){
                        if(min_bri==-1)min_bri=vis[cur.X][cur.Y];
                        else min_bri=min(vis[cur.X][cur.Y],min_bri);
                        break;
                    }
                    if(land[cur.X][cur.Y]==1){
                        vis[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                    else {
                        vis[nx][ny]=vis[cur.X][cur.Y]+1;
                        Q.push({nx,ny});
                    }

                }
            }    
        }
    }
    cout << min_bri;
}