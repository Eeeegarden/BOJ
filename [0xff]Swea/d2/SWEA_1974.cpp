#include <bits/stdc++.h>
using namespace std;

int T;
int board[10][10];

bool chk_box(int x, int y){
    bool a[10]={0,};
    for(int i=x; i-x<3; i++){
        for(int j=y; j-y<3; j++){
            if(a[board[i][j]]!=0)return false;
            a[board[i][j]]=true;
        }
    }
    return true;
}

bool chk_row(int x, int y){
    bool a[10]={0,};
    for(int j=0; j<9; j++){
        if(a[board[x][j]]!=0)return false;
        a[board[x][j]]=true;
    }
    return true;
}

bool chk_col(int x, int y){
    bool a[10]={0,};
    for(int i=0; i<9; i++){
        if(a[board[i][y]]!=0)return false;
        a[board[i][y]]=true;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        bool isval=true;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cin >> board[i][j];
            }
        }
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                if(!isval) break;
                if(chk_box(i,j)==false || chk_row(i,j)==false || chk_col(i,j)==false)isval=false;
            }
        }
        cout << '#' << tc << ' ' << isval << '\n';
    }
}