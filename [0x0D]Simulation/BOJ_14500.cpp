// 푸는중
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int N,M;
int ans=0;
queue<pair<int,int>> Q;

// 각도형별 회전,대칭 경우의수 모두 따져서?
bool isvalid(int nx, int ny){
    if(nx<0 || nx>=N || ny<0 || ny>=M)return false;
    return true;
}

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
            int j=0;
            if(i==2)j=1;
            int nx=cur.X+i;
            int ny=cur.Y+j;
            if(isvalid(nx,ny)==false)break;
            sum+=board[nx][ny];
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
            

// void symmetry(){
//     int tmp[4][4];
//     for(int i=0; i<4; i++){
//         for(int j=0; j<4; j++){
//             tmp[i][j]=


// void rotate(){
//     int tmp[N][M];
//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){
//             tmp[i][j] = board[N-j-1][i];
//         }
//     }
//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++){
//             board[i][j] = tmp[i][j];
//         }
//     }
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    for(int q=0; q<4; q++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                for(int k=0; k<5; k++){
                    poliomino({i,j},k);
                }
            }
        }
        rotate();
    }

    cout << ans;

}