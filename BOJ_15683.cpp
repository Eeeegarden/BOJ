// BKD 풀이방법 참조..
// 변수들이 가질수 있는 값이 여러개 이면서 모든조합 확인필요한데 변수들 독립적이라면 백트래킹보다 진법으로 쉽게풀이가능(방향)

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m[10][10];
int m2[10][10];
int N,M;
int mn=100;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<pair<int,int>> cctv;

// cctv 감시 범위
void upd(int x,int y,int dir){
    dir=dir%4;
    while(1){
        x = x + dx[dir];
        y = y + dy[dir];
        if(x<0 || y<0 || x>=N || y>=M)return;
        if(m[x][y]==6)return;
        if(m[x][y]!=0)continue;
        m2[x][y]=7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> m[i][j];
            m2[i][j]=m[i][j];
            if(m[i][j]!=0 && m[i][j]!=6)cctv.push_back({i,j});
        }
    }

    // cctv가 4개의 방향을 가지고 있을때의 방향의 경우의수 -> i는 4^cctv.size() 까지 참조 -> 4진수 풀이
    for(int i=0; i<(1<<(2*cctv.size())); i++){
        int temp=i;
        int cnt=0;
        for(int j=0; j<cctv.size(); j++){
            int dir = temp%4;
            int x=cctv[j].X;
            int y=cctv[j].Y;
            // dx,dy 무빙이 상하좌우 순이라 if문 처리 어려움
            // 시계방향 무빙이였으면 조금 더 간결한 풀이가능
            if(m[x][y]==1) upd(x,y,dir);
            else if(m[x][y]==2){
                if(dir==0 || dir==2){
                    upd(x,y,dir);
                    upd(x,y,dir+1);
                }
                else {
                    upd(x,y,dir);
                    upd(x,y,dir+3);
                }
            }
            else if(m[x][y]==3){
                if(dir<2){
                    upd(x,y,0);
                    upd(x,y,dir+2);
                }
                else if(dir<4){
                    upd(x,y,1);
                    upd(x,y,dir);
                }
            }
            else if(m[x][y]==4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            else if(m[x][y]==5){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
            temp/=4;
        }

        for(int q=0; q<N; q++){
            for(int w=0; w<M; w++){
                if(m2[q][w]==0)cnt++;
            }
        }

        if(cnt<=mn)mn=cnt;
        copy(m[0],m[0]+100,m2[0]);
    }

    cout << mn;
}