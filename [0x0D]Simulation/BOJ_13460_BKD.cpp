// 4H
// 답지참조BKD

// BFS,백트래킹이용
// cnt<=10이라 모든 경우의수 4^10해도 시간초과 발생X
// 바깥테두리가 # 으로 주어지기때문에 OOB체크 안해도됨

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[12];
int vis[12][12][12][12];
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
pair<int,int> startB,startR;
queue<tuple<int,int,int,int>> Q;

void marble_escape(){
    Q.push({startR.X,startR.Y,startB.X,startB.Y});
    vis[startR.X][startR.Y][startB.X][startB.Y]=0;
    while(!Q.empty()){
        int rx,ry,bx,by;
        tie(rx,ry,bx,by)=Q.front(); Q.pop();
        int cnt=vis[rx][ry][bx][by];
        if(cnt>=10){
            cout << "-1" ;
            return;
        }
        for(int dir=0; dir<4; dir++){
            int n_rx=rx,n_ry=ry,n_bx=bx,n_by=by;
            // 파란색공
            while(board[n_bx+dx[dir]][n_by+dy[dir]]=='.'){
                n_bx+=dx[dir];
                n_by+=dy[dir];
            }
            if(board[n_bx+dx[dir]][n_by+dy[dir]]=='O')continue;
            // 빨간색공
            while(board[n_rx+dx[dir]][n_ry+dy[dir]]=='.'){
                n_rx+=dx[dir];
                n_ry+=dy[dir];
            }
            if(board[n_rx+dx[dir]][n_ry+dy[dir]]=='O'){
                cout << cnt+1 ;
                return;
            }
            // R,B가 뒤따라 출발해 겹쳐진경우 늦게 출발한구슬 한칸뒤로
            if((n_rx == n_bx) && (n_ry == n_by)){
                //아래쪽
                if(dir==0) rx<bx ? n_rx-- : n_bx--;
                //위쪽
                else if(dir==1) rx<bx ? n_bx++ : n_rx++;
                //왼쪽
                else if(dir==2) ry>by ? n_ry++ : n_by++;
                //오른쪽
                else ry<by ? n_ry-- : n_by--;
            }
            if(vis[n_rx][n_ry][n_bx][n_by]!=-1)continue;
            vis[n_rx][n_ry][n_bx][n_by]=cnt+1;
            Q.push({n_rx,n_ry,n_bx,n_by});
        }
    }
    cout << "-1";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> board[i];
        for(int j=0; j<M; j++){
            if(board[i][j]=='B'){
                startB={i,j};
                board[i][j]='.';
            }
            else if(board[i][j]=='R'){
                startR={i,j};
                board[i][j]='.';
            }
        }
    }

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
                fill(vis[i][j][k], vis[i][j][k]+10, -1);

    marble_escape();
}