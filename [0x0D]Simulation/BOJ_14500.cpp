// 2H
// https://www.acmicpc.net/problem/14500

// 도형을 회전,좌우대칭 하는것 보다 board를 회전,대칭 해서 풀었음
// 회전하는 문제 많음 -> 완벽하게 익히기

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
int N,M;
int ans=0;

bool isvalid(int nx, int ny){
    if(nx<0 || nx>=N || ny<0 || ny>=M)return false;
    return true;
}

// 각 도형별 체크
void poliomino(pair<int,int> cur, int t){
    int sum=0;
    if(t==0){
        for(int i=0; i<4; i++){
            int nx=cur.X;
            int ny=cur.Y+i;
            if(isvalid(nx,ny)==false)break;
            sum+=board[nx][ny];
        }
        ans=max(ans,sum);
    }
    else if(t==1){
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                int nx=cur.X+i;
                int ny=cur.Y+j;
                if(isvalid(nx,ny)==false)break;
                sum+=board[nx][ny];
            }
        }
        ans=max(ans,sum);
    }
    else if(t==2){
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++){
                int nx=cur.X+i;
                int ny=cur.Y+j;
                if(i==0&&j==1)continue;
                if(i==1&&j==1)continue;
                if(isvalid(nx,ny)==false)break;
                sum+=board[nx][ny];
            }
        }
        ans=max(ans,sum);
    }
    else if(t==3){
        for(int i=0; i<3; i++){
            for(int j=0; j<2; j++){
                int nx=cur.X+i;
                int ny=cur.Y+j;
                if(i==0&&j==1)continue;
                if(i==2&&j==0)continue;
                if(isvalid(nx,ny)==false)break;
                sum+=board[nx][ny];
            }
        }
        ans=max(ans,sum);
    }
    else {
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                int nx=cur.X+i;
                int ny=cur.Y+j;
                if(i==1&&j==0)continue;
                if(i==1&&j==2)continue;
                if(isvalid(nx,ny)==false)break;
                sum+=board[nx][ny];
            }
        }
        ans=max(ans,sum);
    }
}        
            
// 좌우대칭
void symmetry(){
    int tmp[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmp[i][j]=board[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            board[i][j]=tmp[i][M-1-j];
        }
    }
}

// 90도회전
void rotate(){
    int tmp[M][N];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            tmp[i][j] = board[N-j-1][i];
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    // 좌우대칭 1번
    for(int w=0; w<2; w++){
        // 회전 4번
        for(int q=0; q<4; q++){
            // (0,0)~(N,M) 까지 각 도형 체크
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    for(int k=0; k<5; k++){
                        poliomino({i,j},k);
                    }
                }
            }
            rotate();
            swap(N,M);
        }
        symmetry();
    }
        cout << ans;
}