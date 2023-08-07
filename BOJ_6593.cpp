#include <bits/stdc++.h>
using namespace std;
#define Z get<0>
#define X get<1>
#define Y get<2>
// tuple : get<n>(Q.front()) 형식

char sb[32][32][32];
int dis[32][32][32];
// 상하좌우위아래 순서
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,1,-1};
int l=1,r=1,c=1;
int ez,ex,ey;
queue<tuple<int,int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> l >> r >> c ;
        if(l==0 && r==0 && c==0)break;

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                fill(dis[i][j],dis[i][j]+c,0);
            }
        }

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    cin >> sb[i][j][k];
                    if(sb[i][j][k]=='S'){
                        Q.push({i,j,k});
                        dis[i][j][k]=0;
                    }
                    else if(sb[i][j][k]=='#') dis[i][j][k]=-1;
                    else if(sb[i][j][k]=='E') {
                        ez=i;
                        ex=j;
                        ey=k;
                    }
                }
            }
        }

        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<6; dir++){
                int nz = Z(cur) + dz[dir];
                int nx = X(cur) + dx[dir];
                int ny = Y(cur) + dy[dir];
                if(nz<0 || nz>=l || nx<0 || nx>=r || ny<0 || ny>=c) continue;
                if(dis[nz][nx][ny]>0 || dis[nz][nx][ny]==-1) continue;
                dis[nz][nx][ny] = dis[Z(cur)][X(cur)][Y(cur)]+1;
                Q.push({nz,nx,ny});
            }
        }
        if(dis[ez][ex][ey]!=0)cout << "Escaped in "<< dis[ez][ex][ey] << " minute(s)." << '\n';
        else cout << "Trapped!" << '\n';
    }
}
