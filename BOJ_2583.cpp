// 좌표 입력 -> 칸 체크 ( x1~x2-1 / y1~y2-1 )
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[102][102]={0,};
int vis[102][102]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
vector<int> a;
queue<pair<int,int>> Q;
int m,n,k;
int area=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k ; // m:row n:col

    for(int i=0; i<k; i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=y1; j<y2; j++){
            for(int k=x1; k<x2; k++){
                board[j][k]=1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int width=1;
            if(vis[i][j]==0 && board[i][j]==0){
                Q.push({i,j});
                vis[i][j]=1;
                area++;
            }
            else continue;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
                    if(board[nx][ny]!=0 || vis[nx][ny]!=0) continue;
                    Q.push({nx,ny});
                    vis[nx][ny]=width+1;
                    width++;
                }
            }
            a.push_back(width);
        }
    }
    sort(a.begin(),a.end());

    cout << area << '\n';
    for(auto c : a){
        cout << c << ' ';
    }
}