#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int board[22][22];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int shark_size=2;
int eatcnt=0;
int ans=0;

void fx(int x, int y){
    queue<pair<int,int>> Q;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> PQ;
    int dis[22][22] ;
    for(int i=0; i<22; i++){
        for(int j=0; j<22; j++){
            dis[i][j] = -1;
        }
    }
    Q.push({x,y});
    dis[x][y]=0;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
            if(board[nx][ny]>shark_size || dis[nx][ny]>0) continue;
            // 먹는경우 - 상좌우하 push
            if(board[nx][ny]!=0 && board[nx][ny]<shark_size){
                // 바로 먹는게 아닌 완전탐색 후
                // 우선순위 높은거 먹는과정 필요
                // 우선순위 큐 이용(조건 = 거리, {nx,ny})
                dis[nx][ny] = dis[cur.X][cur.Y]+1;
                PQ.push({dis[nx][ny], {nx,ny}});
            }
            Q.push({nx,ny});
            dis[nx][ny] = dis[cur.X][cur.Y]+1;
        }
    }
    // 이동가능한 좌표 다돌았고 먹을 수 있는 좌표들 PQ에 들어가있는상태
    // 거리, {nx,ny} 순으로 정렬됨
    if(PQ.empty()) return;
    auto target = PQ.top(); PQ.pop();
    int nx = target.Y.X;
    int ny = target.Y.Y;
    board[nx][ny]=0;
    eatcnt++;
    if(eatcnt == shark_size){
        shark_size++;
        eatcnt=0;
    }
    ans += dis[nx][ny];
    mv[nx][ny] = mvcnt++;
    fx(nx,ny);
    return;
}                        

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int s_i,s_j;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                s_i = i; s_j = j;
                board[i][j]=0;
            }
        }
    }
    countdis(s_i,s_j);
    cout << ans;
}