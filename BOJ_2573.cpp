// 알고리즘 상으로 while문안에 반복문이 많이들어가서
// 시간초과가 발생하는줄 알았으나 빙하가 다 녹은경우에도 계속 반복문이 진행되어
// 시간초과가 발생했다. 
// 다음부터 가능하면 함수를 이용해서 조금 더 코드를 보기쉽게 짜보자
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int ice[302][302];
int m_ice[302][302];
int vis[302][302];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int>> Q;
int n,m;
int t=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ice[i][j];
            m_ice[i][j]=ice[i][j];
        }
    }

    while(1){
        int cnt=0;
        // 다녹았는지 확인하는 변수
        bool m_all = 1;
        for(int i=0; i<n; i++){
            fill(vis[i],vis[i]+m,0);
            for(int j=0; j<m; j++){
                ice[i][j] = m_ice[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && ice[i][j]!=0) {
                    Q.push({i,j});
                    vis[i][j]++;
                    cnt++;
                    if(cnt==2){
                        cout << t;
                        return 0;
                    }
                    m_all=0;
                }
                while(!Q.empty()){
                    auto cur = Q.front();Q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        if(vis[nx][ny]!=0) continue;
                        if(ice[nx][ny]==0) {
                            if(m_ice[cur.X][cur.Y]>0)m_ice[cur.X][cur.Y]--;
                        }
                        if(ice[nx][ny]!=0){
                            Q.push({nx,ny});
                            vis[nx][ny]++;
                        }
                        vis[cur.X][cur.Y]++;
                    }
                }
            }
        }
        if(m_all==1){
            cout << 0 ;
            return 0;
        }
        t++;
    }

}