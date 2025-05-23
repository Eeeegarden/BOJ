#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int T;
int N,M;
int board[20][20];
int dx[2]={1,0};
int dy[2]={0,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int testcase=1; testcase<=T; testcase++){
        cin >> N >> M;
        int mx_cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> board[i][j];
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                queue<pair<int,int>> Q;
                bool chk[20][20]={0,};
                int cnt=0;
                if(i+M>N || j+M>N) continue;
                Q.push({i,j});
                cnt+=board[i][j];
                chk[i][j]=1;

                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<2; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx>N || ny>N)continue;
                        if(nx-i>=M || ny-j>=M)continue;
                        if(chk[nx][ny]==1)continue;
                        cnt+=board[nx][ny];
                        Q.push({nx,ny});
                        chk[nx][ny]=1;
                    }
                }
                if(cnt>mx_cnt){
                    mx_cnt=cnt;
                }
            }
        }
        cout << '#' << testcase << ' ' << mx_cnt << '\n';
    }
}