// w,h 에 따른 범위설정 실수로 이주동안 풀고있던 문제
// 이차원배열 이용시 범위 꼼꼼히 파악하기..

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string s[1002];
int maze[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int w,h,t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t ;

    for(int i=0; i<t; i++){
        queue<pair<int,int>> F;
        queue<pair<int,int>> S;
        int disS=1000002;
        cin >> w >> h ; 
        for(int k=0; k<h; k++){
            // 1로 초기화함으로써 못가는곳설정
            fill(maze[k],maze[k]+w,1);
            fill(visF[k],visF[k]+w,0);
            fill(visS[k],visS[k]+w,0);
            cin >> s[k];
            for(int j=0; j<s[k].length(); j++){
                if(s[k][j]=='#')maze[k][j]=1;
                if(s[k][j]=='*'){
                    maze[k][j]=1;
                    visF[k][j]=1;
                    F.push({k,j});
                }
                if(s[k][j]=='@'){
                    maze[k][j]=0;
                    visS[k][j]=1;
                    S.push({k,j});
                }
                if(s[k][j]=='.')maze[k][j]=-1;
            }
        }
        // 불 탈출거리계산
        while(!F.empty()){
            auto cur = F.front(); F.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>h || ny>w) continue;
                if(maze[nx][ny]>0) continue;
                if(visF[nx][ny]) continue;
                visF[nx][ny]=visF[cur.X][cur.Y]+1;
                F.push({nx,ny});
            }
            
        }
        // 상근 탈출거리계산
        while(!S.empty()){
            auto cur = S.front(); S.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>h || ny>w) continue;
                if(maze[nx][ny]>0 || visS[nx][ny]>0) continue;
                if(visF[nx][ny]!=0 && visF[nx][ny]<=visS[cur.X][cur.Y]+1) continue;
                visS[nx][ny]=visS[cur.X][cur.Y]+1;
                S.push({nx,ny});
            }
        }
        for(int k=0; k<h; k++){
            for(int j=0; j<w; j++){
                if((k==0 || k==h-1) && visS[k][j] !=0){
                    if(disS>visS[k][j]) disS=visS[k][j];
                }
                if((j==0 || j==w-1) && visS[k][j] !=0){
                    if(disS>visS[k][j]) disS=visS[k][j];
                }
            }
        }
        if(disS==1000002)cout << "IMPOSSIBLE" << '\n';
        else cout << disS << '\n';
    }
}