// 푸는중
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int body[102][102]={0,};
char change[102];
// 동->남(시계방향)
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans=0;

int N,K,L,dir;
queue<pair<int,int>> Q;
stack<pair<int,int>> S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<K; i++){
        int x,y;
        cin >> x >> y;
        board[x][y]=1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        int tmp;
        char tmp_c;
        cin >> tmp >> tmp_c;
        change[tmp]=tmp_c;
    }

    S.push({0,0});
    Q.push({0,0});
    dir=0;
    body[0][0]=1;
    
    while(!S.empty()){
        if(change[ans]=='D')dir=(dir+1)%4;
        if(change[ans]=='L')dir=(dir+3)%4;
        auto cur = S.top(); S.pop();
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx<0 || nx>=N || ny<0 || ny>=N)break;
        if(body[nx][ny]!=0)break;
        if(board[nx][ny]==1){
            board[nx][ny]=0;
            Q.push({nx,ny});
            body[nx][ny]=1;
            S.push({nx,ny});
        }
        else {
            body[Q.front().X][Q.front().Y]=0;
            body[nx][ny]=1;
            Q.pop();
            Q.push({nx,ny});
            S.push({nx,ny});
        }
        cout << "--------------------" << '\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j]==1) cout << '*' << ' ';
                else cout << body[i][j] << ' ';
            }
            cout << '\n';
        }
        ans++;
    }
    cout << ans;
}