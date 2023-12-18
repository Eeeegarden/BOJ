#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[26];
int vis[26][26];
int n;
int seq=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int>> Q;
vector<int> house;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        fill(vis[i],vis[i]+n,-1);
        cin >> board[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt=0;
            if(board[i][j]=='1' && vis[i][j]==-1){
                Q.push({i,j});
                vis[i][j]=0;
                seq++;
            }       
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                cnt++;
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    if(vis[nx][ny]>0 || board[nx][ny]=='0') continue;
                    vis[nx][ny]=seq;
                    Q.push({nx,ny});
                }
            }
            if(cnt==1)house.push_back(cnt);
            else if(cnt!=0)house.push_back(cnt-1);
        }
    }
    sort(house.begin(),house.end());
    cout << seq << '\n';
    for(auto c : house){
        cout << c << '\n';
    }
}