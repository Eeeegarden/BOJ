// 5H30M...
// 회전하는과정에서 초기의 값에서 회전을 시키는게 아니라 회전된 상태에서 또 회전을 구현하고있는 에러가있었음.. -> 해결

// 로직: 
// 모든경우의수 체크
// 판의 순서 순열(next_permutation) -> 각 판 회전(rotate)

#include <bits/stdc++.h>
using namespace std;

int board[5][5][5]={0,};
int t_board[5][5][5]={0,};
int m_board[5][5][5]={0,};
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};
int ans=INT_MAX;


void rotate(int Z){
    int tmp[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            tmp[i][j] = t_board[Z][5-j-1][i];
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            t_board[Z][i][j] = tmp[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                cin >> board[i][j][k];
            }
        }
    }

    vector<int> v{0,1,2,3,4};

    do{
        // 판순서 구현
        int q=0;
        for(auto z=v.begin(); z!=v.end(); z++){
            // 순서바뀐 판을 t_board에 복사
            // 순서바뀐 판의 t_board를 m_board에 복사해서 회전할때 초기값 복원가능하도록유지
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    t_board[q][i][j]=board[*z][i][j];
                    m_board[q][i][j]=board[*z][i][j];
                }
            }
            q++;
        }

        // 회전 구현
        for(int tmp=0; tmp<1024; tmp++){
            int brute=tmp;
            // 이전에 돌아간 판 초기값으로 설정
            for(int q=0; q<5; q++){
                for(int i=0; i<5; i++){
                    for(int j=0; j<5; j++){
                        t_board[q][i][j]=m_board[q][i][j];
                    }
                }
            }
            // 회전
            for(int i=0; i<5; i++){
                int n=brute%4;
                brute/=4;
                while(n--)rotate(i);
            }
            // 순서와 회전이 정해진 큐브미로 BFS시작
            int vis[5][5][5]={0,};
            queue<tuple<int,int,int>> Q;
            if(t_board[0][0][0]==0 || t_board[4][4][4]==0)continue;
            Q.push({0,0,0});
            vis[0][0][0]=1;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                int curX,curY,curZ;
                tie(curZ, curX, curY) = cur;
                for(int dir=0; dir<6; dir++){
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];
                    int nz = curZ + dz[dir];
                    if(nx<0 || nx>=5 || ny<0 || ny>=5 || nz<0 || nz>=5)continue;
                    if(vis[nz][nx][ny]!=0 || t_board[nz][nx][ny] == 0) continue;
                    vis[nz][nx][ny] = vis[curZ][curX][curY] + 1;
                    Q.push({nz,nx,ny});
                    if(nz == 4 && nx == 4 && ny == 4) {
                        ans = min(ans, vis[nz][nx][ny]);
                    }
                }
            }
        }
    }while(next_permutation(v.begin(),v.end()));

    if(ans==INT_MAX)cout << -1;
    else cout << ans-1;
}