#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int p_dis=0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    queue<pair<int,int>> Q;

    cin >> n >> m;
    
    string maze[n];
    for(int i=0; i<n; i++){
        cin >> maze[i];
    }

    // 다음부터 중간에 배열 선언하지않기
    int dis[n][m];
    fill(dis[0],dis[n],-1);
    Q.push({0,0});

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        p_dis=dis[cur.X][cur.Y]++;
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if((nx<0 || nx>=n) || (ny<0 || ny>=m))continue;
            if(dis[nx][ny]>=0 || maze[nx][ny]=='0')continue;
            Q.push({nx,ny});
            dis[nx][ny]=p_dis+1;
        }
    }
    cout << dis[n-1][m-1]+1;
}