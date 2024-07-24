// 1H30M

// 이런문제 대부분이 (0,0) 이아닌 (1,1) 부터 시작하는것 잘 체크하기
// 문제만 빠르게 이해하면 금방풀수있는문제인듯

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102];
int body[102][102]={0,};
char change[10002];
// 동->남(시계방향) : 초기에 동쪽으로 시작함
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans=0;

int N,K,L,dir;
// 뱀길이 queue
queue<pair<int,int>> Q;
// 이동 stack
stack<pair<int,int>> S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<K; i++){
        int x,y;
        cin >> x >> y;
        board[x-1][y-1]=1;
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
        // 방향조정되는경우
        if(change[ans]=='D')dir=(dir+1)%4;
        if(change[ans]=='L')dir=(dir+3)%4;
        auto cur = S.top(); S.pop();
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        // 벽이나 몸통마주치는경우
        if(nx<0 || nx>=N || ny<0 || ny>=N)break;
        if(body[nx][ny]!=0)break;
        // 사과있는경우
        if(board[nx][ny]==1){
            board[nx][ny]=0;
            Q.push({nx,ny});
            body[nx][ny]=1;
            S.push({nx,ny});
        }
        // 사과없는경우
        else {
            body[Q.front().X][Q.front().Y]=0;
            body[nx][ny]=1;
            Q.pop();
            Q.push({nx,ny});
            S.push({nx,ny});
        }
        ans++;
    }
    cout << ans+1;
}