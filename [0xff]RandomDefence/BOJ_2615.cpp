#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[20][20];
int vis[4][20][20]={0,};
// 방향은 상하, 좌우, 오른대각, 왼대각
// 왼->위 우선출력
int dx[8] = {-1,1,0,0,-1,1,1,-1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};
int ans_col;
int ans_row;
bool exist_winner=false;
stack<pair<int,int>> S1;

// 좌표의 오목 시작방향 리스트 반환 함수
list<int> chk_dir(int x, int y){
    list<int> l;
    for(int q=0; q<8; q++){
        int nx = x + dx[q];
        int ny = y + dy[q];
        if(board[x][y] == board[nx][ny] && vis[q/2][nx][ny] == 0) {
            l.push_front(q);
        }
    }
    return l;
}

// 온전한 5목인지 체크함수(6목이상X)
bool chk_5mok(int x, int y){
    for(int q=0; q<8; q++){
        int nx = x + dx[q];
        int ny = y + dy[q];
        if(board[x][y] == board[nx][ny] && vis[q/2][nx][ny] > 5) return false;
    }
    return true;
}

// 5목 시작점 찾는 함수(왼->위 우선)
pair<int,int> start_5mok(int x, int y, int dir){
    pair<int,int> first_stone = {x,y};
    int q = dir*2;
    int nx = x + dx[q];
    int ny = y + dy[q];
    if(vis[dir][nx][ny] == 4){
        for(int z=0; z<3; z++){
            nx += dx[q];
            ny += dy[q];
        }
        first_stone.X = nx; first_stone.Y = ny;
        return first_stone;
    }
    return first_stone;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(board[i][j] == 0) continue;
            // 방향 리스트 저장
            list<int> dir_l;
            dir_l = chk_dir(i,j);

            while(!dir_l.empty()){
                int dir = dir_l.front(); dir_l.pop_front();
                if(board[i][j] == 1 && vis[dir/2][i][j] == 0){
                    S1.push({i,j});
                    vis[dir/2][i][j] = 1;
                    while(!S1.empty()){
                        auto cur = S1.top(); S1.pop();
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || ny<0 || nx>=19 || ny>=19) continue;
                        if(vis[dir/2][nx][ny] !=0) continue;
                        if(board[i][j] != board[nx][ny]) continue;
                        vis[dir/2][nx][ny]=vis[dir/2][cur.X][cur.Y]+1;
                        S1.push({nx,ny});
                    }
                }
                if(board[i][j] == 2 && vis[dir/2][i][j] == 0){
                    S1.push({i,j});
                    vis[dir/2][i][j] = 1;
                    while(!S1.empty()){
                        auto cur = S1.top(); S1.pop();
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || ny<0 || nx>=19 || ny>=19) continue;
                        if(vis[dir/2][nx][ny] !=0) continue;
                        if(board[i][j] != board[nx][ny]) continue;
                        vis[dir/2][nx][ny]=vis[dir/2][cur.X][cur.Y]+1;
                        S1.push({nx,ny});
                    }
                }
            }
        }
    }
    for(int dir=0; dir<4; dir++){
        for(int i=0; i<19; i++){
            for(int j=0; j<19; j++){
                // 온전한 5목인지 체크
                if(vis[dir][i][j] == 5 && chk_5mok(i,j)){
                    auto ans = start_5mok(i,j,dir);
                    ans_row = ans.X; ans_col=ans.Y;
                    cout << board[i][j] << '\n' << ans_row+1 << ' ' << ans_col+1 ;
                    exist_winner=true;
                }
            }
        }
    }
    if(exist_winner == false) cout << "0";
}