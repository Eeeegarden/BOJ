// 3일동안 푼 문제..
// 퀸의 방향에따라 함수진행시 +1 백트래킹시 -1 해주면서
// n번 행까지 도달하게되면 ans++
// 그냥 직관적으로 퀸의 방향을 모두 체크해서 코드가 길어짐

// 열,왼쪽대각,오른쪽대각 열을 체크하는 배열로 조금 더 간단하게 구현가능
// y, x+y, x-y+n-1

#include <bits/stdc++.h>
using namespace std;

int board[17][17];
int isused[17][17];
int n;
int ans=0;

void Qmov(int row, int col,int t){
    for(int dir=0; dir<6; dir++){
        int x=row;
        int y=col;
        //row
        if(dir==0){
            for(int i=0; i<n; i++){
                isused[x][i]+=t;
            }
        }
        //col
        if(dir==1){
            for(int i=0; i<=n; i++){
                isused[i][y]+=t;
            }
        }
        //남동
        if(dir==2){
            while(x>=0 && y>=0 && x<n && y<n){
                isused[x][y]+=t;
                x++;
                y++;
            }
        }
        //북서
        if(dir==3){
            while(x>=0 && y>=0 && x<n && y<n){
                isused[x][y]+=t; 
                x--;
                y--;
            }
        }//북동
        if(dir==4){
            while(x>=0 && y>=0 && x<n && y<n){
                isused[x][y]+=t; 
                x--;
                y++;
            }
        }//남서
        if(dir==5){
            while(x>=0 && y>=0 && x<n && y<n){
                isused[x][y]+=t;
                x++;
                y--;
            }
        }
    }
}

void func(int row){
    if(row==n){
        ans++;
        return;
    }
    for(int i=0; i<n; i++){
        if(isused[row][i]==0){
            board[row][i]=1;
            Qmov(row,i,1);
            func(row+1);
            board[row][i]=0;
            Qmov(row,i,-1);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    func(0);

    cout << ans;
}