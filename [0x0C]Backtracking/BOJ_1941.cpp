// 풀이방법 참조... 오래걸린문제
// 모든 시작점 BFS -> 시간초과 , DFS -> 십자가 같은 모양 체크 어려움
// 25C7로 후보군 선택 -> BFS로 후보군 이어져있는지 확인 -> 이다솜파 4명이상인지 체크, 카운트
// 25C7 -> 대략 400000 ->  2초미만 실행가능

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string m[5];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
vector<int> temp(25);
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++){
        cin >> m[i];
    }
    // prev_permutation 조합세팅 
    fill(temp.begin(),temp.begin()+7,1);

    do{
        queue<pair<int,int>> Q;
        bool vis[5][5]={0,};
        bool pick[5][5]={0,};
        int x,y;
        int dasom=0;
        int cnt=0;
        // 골라진 부분 check표시, 첫 좌표 큐에 푸시
        for(int i=0; i<25; i++){
            x=i/5; y=i%5;
            if(temp[i]==1){
                pick[x][y]=true;
                if(Q.empty()){
                    Q.push({x,y});
                    if(m[x][y]=='S')dasom++;
                    vis[x][y]=1;
                    cnt++;
                }
            }
        }
        // 시작점 기준으로 bfs 돌려서 이어져있는지 확인
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny<0 || nx>=5  || ny>=5)continue;
                if(vis[nx][ny]!=0)continue;
                if(pick[nx][ny]!=1)continue;
                Q.push({nx,ny});
                if(m[nx][ny]=='S')dasom++;
                vis[nx][ny]=1;
                cnt++;
            }
        }
        if(cnt==7 && dasom>=4){
            ans++;
        }
    }while(prev_permutation(temp.begin(), temp.end()));

    cout << ans;
}