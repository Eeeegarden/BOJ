
// 시간복잡도 때문에 고생한문제.. 
// 벽 통과하면서 벽부순경우거리 안부순경우거리 두가지를 계산하면서 가야 O(2*NM)으로 해결가능
// 벽을 부쉈을경우 BFS, 안부쉈을경우 BFS 따지면서 간다면 시간초과발생

// 아래 Tips 참고함
// 모든 칸을 전부 0으로 하나씩 바꾸어보고 BFS를 돌리는 것을 반복해서는 통과될 수 없습니다. 
// 대부분의 알고리즘 문제가 그렇듯이, 풀이를 짜기 전에 반드시 해야 하는 것 중 하나는 시간 복잡도를 생각하는 것입니다. 
// 시간 복잡도 계산, 전혀 어렵지 않습니다. 
// 벽이 최대 O(NM)개 있는 맵에서, 벽을 하나 부술 때마다 O(NM)개의 칸을 탐색해야 하죠? 그러니 O((NM)^2)입니다. 
// 이 수는 우리가 대충 1초에 돌 수 있다고 보는 단위인 1억을 10000배나 뛰어넘는 1조입니다. 절대 통과될 수 없을 것입니다.

#include <bits/stdc++.h>
using namespace std;

char wall[1002][1002];
int dis[2][1002][1002];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n,m;
queue<tuple<int,int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        fill(dis[0][i],dis[0][i]+m,-1);
        fill(dis[1][i],dis[1][i]+m,-1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> wall[i][j];
            if(wall[i][j]=='0'){
                dis[0][i][j]=0;
                dis[1][i][j]=0;
            }
        }
    }

    Q.push({0,0,0});
    dis[0][0][0]=1;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nz = get<0>(cur);
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dis[nz][nx][ny]>0) continue;
            if(nz=='1' && wall[nx][ny]=='1') continue;
            if(wall[nx][ny]=='1' && nz==0){
                dis[1][nx][ny]=dis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push({1,nx,ny});
            }
            else if(wall[nx][ny]=='0' && nz==0){
                dis[0][nx][ny]=dis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push({0,nx,ny});
            }
            else if(wall[nx][ny]=='0' && nz==1){
                dis[1][nx][ny]=dis[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push({1,nx,ny});
            }
        }
    }

    if(dis[0][n-1][m-1]==0 && dis[1][n-1][m-1]==0) cout << "-1" ;
    else {
        if(dis[0][n-1][m-1]==0) cout << dis[1][n-1][m-1];
        else if(dis[1][n-1][m-1]==0) cout << dis[0][n-1][m-1];
        else cout << min(dis[0][n-1][m-1],dis[1][n-1][m-1]);
    }
}