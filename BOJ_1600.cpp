// 벽 부수고 이동하기(BOJ_2206)와 비슷한 방식의 문제
// 3차원 vis를 이용하여 BFS 진행하면서 계산을 해주었다.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[202][202];
int vis[31][202][202];
int dx[12]={1,2,2,1,-1,-2,-2,-1,1,-1,0,0};
int dy[12]={-2,-1,1,2,2,1,-1,-2,0,0,-1,1};
int ans=100000;
int k,w,h;
queue<tuple<int,int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cin >> w >> h;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> board[i][j];
            if(board[i][j]==1){
                for(int q=0; q<=k; q++){
                    vis[q][i][j]=-1;
                }
            }
            else {
                for(int q=0; q<=k; q++){
                    vis[q][i][j]=0;
                }
            }
        }
    }
    
    Q.push({0,0,0});
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<12; dir++){
            int nz = get<0>(cur);
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nx<0 || ny<0 || nx>=h || ny>=w || nz<0 || nz>k) continue;
            if(vis[nz][nx][ny]!=0 && vis[nz][nx][ny]<=vis[nz][get<1>(cur)][get<2>(cur)]+1) continue;
            if(board[nx][ny]==1)continue;
            // 말의 움직임을 할경우
            if(dir<8){
                if(vis[nz+1][nx][ny]==0 || vis[nz+1][nx][ny]>vis[nz][get<1>(cur)][get<2>(cur)]+1){
                    vis[nz+1][nx][ny]=vis[nz][get<1>(cur)][get<2>(cur)]+1;
                    Q.push({nz+1,nx,ny});
                }
            }
            // 원숭이 움직임할경우
            else {
                if(vis[nz][nx][ny]==0 || vis[nz][nx][ny]>vis[nz][get<1>(cur)][get<2>(cur)]+1){
                    vis[nz][nx][ny]=vis[nz][get<1>(cur)][get<2>(cur)]+1;
                    Q.push({nz,nx,ny});
                }
            }
        }
    }    
    
    // 1개인경우 예외처리 
    if((w==1 && h==1) && board[0][0]==0){
        cout << "0" ;
        return 0;
    }
    // 탈출하는 경우의 수 중 최솟값 찾기
    for(int q=0; q<=k; q++){
        if(vis[q][h-1][w-1]!=0)ans=min(ans,vis[q][h-1][w-1]);
    }
    if(ans==100000) cout << "-1";
    else cout << ans;

}
