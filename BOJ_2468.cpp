//수정중5...

#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int hei[102][102];
int vis[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int max_hei=0;
int max_cnt=0;
queue<pair<int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> hei[i][j];
            if(hei[i][j]>=max_hei)max_hei=hei[i][j];
        }
    }


    for(int h=1; h<100; h++){
        int cnt=1;
        for(int k=0; k<n; k++){
            fill(vis[k],vis[k]+n,0);
        }
        Q.push({0,0});
        vis[0][0]=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){   
                int area=0;
                while(!Q.empty()){
                    area++;
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                        if(vis[nx][ny]>0 || hei[nx][ny]>h) continue;
                        vis[nx][ny]=cnt;
                        Q.push({nx,ny});
                    }
                }
                if(area!=0)cnt++;
            }
        }
        if(cnt>=max_cnt)max_cnt=cnt;
        cout << max_cnt << '\n';
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << max_cnt;
}




    