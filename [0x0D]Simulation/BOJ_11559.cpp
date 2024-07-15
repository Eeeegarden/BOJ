// 2H 1M
// 기본문제인데 ,,,, 

// BFS 돌리고 BFS깊이가 4 이상이면 뿌요체크, . 으로 바꿈, isbuyo=true
// 뿌요폭발 일어난 부분 위에서부터 블록밀어주기
// isbuyo=true 리턴시키면서 ans++ , while문의 BFS 다시실행

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

char board[14][8];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
queue<pair<int,int>> Q;
int ans=0;


bool BFS(){
    bool vis[14][8]={0,};
    bool buyo[14][8]={0,};
    bool isbuyo=false;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(board[i][j]!='.' && vis[i][j]==0){
                int tmp[14][8]={0,};
                int cnt=1;
                Q.push({i,j});
                vis[i][j]=1;
                tmp[i][j]=1;
                while(!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || nx>=12 || ny<0 || ny>=6)continue;
                        if(vis[nx][ny]==1)continue;
                        // . 이나 색 다르면 패스
                        if(board[nx][ny]=='.' || (board[nx][ny]!=board[i][j]))continue;
                        Q.push({nx,ny});
                        vis[nx][ny]=1;
                        tmp[nx][ny]=tmp[cur.X][cur.Y]+1;
                        cnt++;
                    }
                }
                // 4개이상붙어있으면 뿌요표시, .으로 바꿈
                if(cnt>=4){
                    for(int k=0; k<12; k++){
                        for(int q=0; q<6; q++){
                            if(tmp[k][q]!=0){
                                board[k][q]='.';
                                buyo[k][q]=1;
                            }
                        }
                    }
                    isbuyo=true;
                }
            }
        }
    }
    // . 으로 바뀐부분 위에서 아래로 밀어주기
    for(int j=0; j<6; j++){
        for(int i=11; i>0; i--){
            if(buyo[i][j]==1){
                int curx=i;
                while(buyo[i][j]==1){
                    // curx 범위 표시 안하면 런타임에러남 조심
                    if(curx<0)break;
                    if(buyo[curx][j]==0){
                        swap(board[i][j],board[curx][j]);
                        swap(buyo[i][j],buyo[curx][j]);
                        break;
                    }
                    curx--;
                }
            }
        }
    }
    return isbuyo;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin >> board[i][j];
        }
    }
    while(BFS()){
        ans++;
    }
    cout << ans;   
}

