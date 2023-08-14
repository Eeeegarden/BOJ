// 시간초과.. 알고리즘 수정중3

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
vector<pair<int,int>> V;
int n,m;
int t=0;
bool m_all = 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ice[i][j];
            m_ice[i][j]=ice[i][j];
            if(ice[i][j])V.push_back({i,j});
        }
    }

    while(1){
        int cnt=0;
        for(int i=0; i<n; i++){
            fill(vis[i],vis[i]+m,0);
            for(int j=0; j<m; j++){
                ice[i][j] = m_ice[i][j];
            }
        }
        // 벡터 사이즈로 빙하 개수확인하기
        Q.push({V.front().X,V.front().Y});
        vis[V.front().X][V.front().Y]++;
        cnt++;
        m_all=0;
        while(!Q.empty()){
            auto cur = Q.front();Q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(vis[nx][ny]!=0) continue;
                if(ice[nx][ny]==0) {
                    if(m_ice[cur.X][cur.Y]>0)m_ice[cur.X][cur.Y]--;
                    vis[cur.X][cur.Y]++;
                }
                if(ice[nx][ny]!=0){
                    vis[cur.X][cur.Y]++;
                    Q.push({nx,ny});
                    vis[nx][ny]++;
                }
            }
        }





        // 시간초과 알고리즘
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(vis[i][j]==0 && ice[i][j]!=0) {
        //             Q.push({i,j});
        //             vis[i][j]++;
        //             cnt++;
        //             m_all=0;
        //         }
        //         while(!Q.empty()){
        //             auto cur = Q.front();Q.pop();
        //             for(int dir=0; dir<4; dir++){
        //                 int nx = cur.X + dx[dir];
        //                 int ny = cur.Y + dy[dir];
        //                 if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        //                 if(vis[nx][ny]!=0) continue;
        //                 if(ice[nx][ny]==0) {
        //                     if(m_ice[cur.X][cur.Y]>0)m_ice[cur.X][cur.Y]--;
        //                     vis[cur.X][cur.Y]++;
        //                 }
        //                 if(ice[nx][ny]!=0){
        //                     vis[cur.X][cur.Y]++;
        //                     Q.push({nx,ny});
        //                     vis[nx][ny]++;
        //                 }
        //             }
        //         }
        //         if(cnt==2){
        //             cout << t;
        //             return 0;
        //         }
        //     }
        // }
        // if(m_all==1){
        //     cout << 0 ;
        //     return 0;
        // }


        // 출력
        // cout << "------------------";
        // cout << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << m_ice[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        t++;
    }

}