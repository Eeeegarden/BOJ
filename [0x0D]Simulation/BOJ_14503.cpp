// 2H

// 한방향으로 쭉가는게 아니라
// 4칸중 빈곳이있으면 먼저 방향을돌림 ;;
// 문제잘읽기

// 청소기 무빙 DFS -> stack
// vis[cur.X][cur.Y]+1 로 쌓는게 아니라 청소된 칸의 개수필요하니까 ans+1로 쌓기

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[52][52];
int vis[52][52]={0,};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int N,M;
int fx,fy,dir;
int ans=1;
stack<pair<int,int>> S;

// 인접 4칸중 빈칸있는지 체크함수
bool check_fx(int x, int y){
    for(int dir=0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
        if(vis[nx][ny]!=0)continue;
        if(board[nx][ny]==1)continue;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> fx >> fy >> dir;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    S.push({fx,fy});
    vis[fx][fy]=1;
    while(!S.empty()){
        auto cur = S.top(); S.pop();
        // 4칸중 빈칸있으면
        if(check_fx(cur.X,cur.Y)==true){
            dir=(dir+3)%4;
            for(int d=dir,n=0; n<4; d=(d+3)%4,n++){
                int nx = cur.X + dx[d];
                int ny = cur.Y + dy[d];
                if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
                if(vis[nx][ny]!=0)continue;
                if(board[nx][ny]==1)continue;
                dir=d;
                S.push({nx,ny});
                vis[nx][ny]=ans+1;
                ans=max(ans,vis[nx][ny]);
                break;
            }
        }
        // 4칸중 빈칸없으면
        else{
            int bx = cur.X + dx[(dir+2)%4];
            int by = cur.Y + dy[(dir+2)%4];
            if(board[bx][by]==1)break;
            else S.push({bx,by});
        }
    }
    cout << ans;
}