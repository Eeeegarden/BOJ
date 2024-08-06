// 1H 30M

// 좌표 세개 뽑는 방식이 어려웠음
// line:64 ~ line:77

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int board[10][10];
int board2[10][10];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int ans=0;
vector<pair<int,int>> safe;
vector<pair<int,int>> virus;
queue<pair<int,int>> Q;

void bfs_virus(int board[10][10]){
    int board2[10][10];
    // 판복사
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            board2[i][j]=board[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<virus.size(); i++)Q.push({virus[i].X,virus[i].Y});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=M)continue;
            if(board2[nx][ny]!=0)continue;
            board2[nx][ny]=2;
            Q.push({nx,ny});
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board2[i][j]==0)cnt++;
        }
    }
    ans=max(ans,cnt);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j]==0)safe.push_back({i,j});
            if(board[i][j]==2)virus.push_back({i,j});
        }
    }

    // 0인 좌표 세개 뽑아서 벽만들기
    for(int q=0; q<safe.size(); q++){
        board[safe[q].X][safe[q].Y]=1;
        for(int w=q+1; w<safe.size(); w++){
            board[safe[w].X][safe[w].Y]=1;
            for(int e=w+1; e<safe.size(); e++){
                board[safe[e].X][safe[e].Y]=1;
                bfs_virus(board);
                board[safe[e].X][safe[e].Y]=0;
            }
            board[safe[w].X][safe[w].Y]=0;
        }
        board[safe[q].X][safe[q].Y]=0;
    }
    cout << ans;
}