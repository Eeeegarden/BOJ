#include <bits/stdc++.h>
using namespace std;

// {높이,행,열} 순으로 계산
#define Z first.first
#define Y first.second
#define X second

int box[102][102][102];
int day[102][102][102];
queue<pair<pair<int,int>,int>> Q;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, h; // n=col ,m=row, h=height
    int dx[6] = {-1,1,0,0,0,0};
    int dy[6] = {0,0,-1,1,0,0};
    int dz[6] = {0,0,0,0,-1,1}; // -1,0,1
    int fin_d = 0;
    int plus_d = 0;

    fill(day[0][0],day[101][102],-1);

    cin >> n >> m >> h;

    for(int i=0; i<h; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) {
                    Q.push({{i,j},k}); // Q(h,m,n)
                    day[i][j][k]=0;
                }
            }
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<6; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int nz = cur.Z + dz[dir];
            if((nx<0 || nx>=n) || (ny<0 || ny>=m) || (nz<0 || nz>=h)) continue;
            if(day[nz][ny][nx]>=0)continue;
            if(box[nz][ny][nx] == -1) continue;
            Q.push({{nz,ny},nx});
            day[nz][ny][nx]=day[cur.Z][cur.Y][cur.X]+1;
            if(fin_d<=day[nz][ny][nx])fin_d=day[nz][ny][nx];
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                if(day[i][j][k]==-1 && box[i][j][k]==0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << fin_d ; 
}