// 푸는중
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string s[6];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++){
        cin >> s[i];
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            queue<pair<int,int>> Q;
            bool vis[6][6]={0,};
            int curvis=0;
            char curchar;
            int cnt=0;
            int ynum=0;
            Q.push({i,j});
            vis[i][j]=1;
            if(s[i][j]=='Y')ynum++;
            cnt++;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                if(vis[cur.X][cur.Y]!=0 && curvis>vis[cur.X][cur.Y]){
                    if(curchar=='Y')ynum--;
                    cnt--;
                }
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || ny<0 || nx>=5 || ny>=5)continue;
                    if(vis[nx][ny]!=0)continue;
                    if(ynum==3 && s[nx][ny]=='Y')continue;
                    Q.push({nx,ny});
                    vis[nx][ny]=vis[cur.X][cur.Y]+1;
                    curvis=vis[nx][ny];
                    curchar=s[nx][ny];
                    cnt++;
                    if(s[nx][ny]=='Y')ynum++;
                }
                if(cnt==7 && ynum<=3){
                    ans++;
                    cout << "----------------" << '\n';
                    cout << i << j <<'\n';
                    for(int q=0; q<5; q++){
                        for(int w=0; w<5; w++){
                            cout << vis[q][w];
                        }
                        cout << '\n';
                    }
                    cout << "----------------" << '\n';
                    break;
                }
                cout << "----------------" << '\n';
                    cout << i << j <<' ' <<cnt <<'\n';
                    for(int q=0; q<5; q++){
                        for(int w=0; w<5; w++){
                            cout << vis[q][w];
                        }
                        cout << '\n';
                    }
                    cout << "----------------" << '\n';
            }
        }
    }
    cout << ans;
}