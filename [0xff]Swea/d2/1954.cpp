// DFS 라 생각해서 스택인줄 알았지만 스택으로 안풀림 -> Queue활용
// 변형 DFS?


#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int Map[11][11];
int vis[11][11];
int number[11];
int test_case;
int Round=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int dir;
queue<pair<int,int>> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;

    for(int i=0; i<test_case; i++){
        cin >> number[i];
    }

    for(int i=0; i<test_case; i++){
        int max_N = number[i];
        Round++;
        cout << "#" << Round << '\n';
        for(int j=0; j<11; j++){
            for(int k=0; k<11; k++){
                Map[j][k]=0;
                vis[j][k]=0;
            }
        }

        Q.push({0,0});
        Map[0][0]=1;
        vis[0][0]=1;
        dir=0;

        while(!Q.empty()){
            auto cur = Q.front();

            // 4방향 탐색 
            for(int i=0; i<4; i++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                // 못가면 90도 회전
                if(nx<0 || ny<0 || nx>=max_N || ny>=max_N || vis[nx][ny]!=0 || Map[nx][ny]!=0){
                    dir=(dir+1)%4;
                    continue;
                }
                // 갈 수 있으면 증가
                Map[nx][ny]=Map[cur.X][cur.Y]+1;
                vis[nx][ny]=1;
                Q.push({nx,ny});
                break;
            }
            // Queue에 1개만 유지
            if(!Q.empty())Q.pop();
        }

        for(int i=0; i<max_N; i++){
            for(int j=0; j<max_N; j++){
                cout << Map[i][j] << ' ' ;
            }
            cout << '\n';
        }
    }
    return 0;
}