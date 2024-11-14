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
stack<pair<int,int>> Q;

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
        // 맵 초기화
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

        // while(!Q.empty()){
        //     auto cur = Q.top(); Q.pop();
        //     int nx = cur.X + dx[dir];
        //     int ny = cur.Y + dy[dir];
        //     if(nx<0 || ny<0 || nx>=max_N || ny>=max_N || vis[nx][ny]!=0 || Map[nx][ny]!=0){
        //         dir=(dir+1)%4;
        //         nx = cur.X + dx[dir];
        //         ny = cur.Y + dy[dir];
        //     }
            
        //     Map[nx][ny]=Map[cur.X][cur.Y]+1;
        //     vis[nx][ny]=1;
        //     Q.push({nx,ny});
            
        // }

        for(int i=0; i<max_N; i++){
            for(int j=0; j<max_N; j++){
                cout << Map[i][j] << ' ' ;
            }
            cout << '\n';
        }
    }
    return 0;
}