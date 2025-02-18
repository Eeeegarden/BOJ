// 1H
#include <bits/stdc++.h>
using namespace std;

int N;
int board[2500][2500];
bool check[2500][2500];
int ans[3]={0,};

bool issame(int x, int y, int n){
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(board[x][y] != board[i][j])return false;
        }
    }
    return true;
}

void fx(int x, int y, int n){
    if(issame(x,y,n)==true){
        if(board[x][y] == -1) ans[0]++;
        else if(board[x][y] == 0) ans[1]++;
        else ans[2]++;
    }
    else{
        for(int i=x; i<x+n; i=i+n/3){
            for(int j=y; j<y+n; j=j+n/3){
                fx(i,j,n/3);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }
    fx(0,0,N);

    cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];
    
}