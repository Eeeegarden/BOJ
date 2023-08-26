#include <bits/stdc++.h>
using namespace std;

char arr[7000][7000];

void stampstar(int row,int col,int n){
    int box=n/3;
    if(n==1){
        arr[row][col]='*';
        return;
    }
    for(int i=row; i<row+n; i+=box){
        for(int j=col; j<col+n; j+=box){
            // 이렇게 예외처리 하기 힘듬 좀더 컴팩트하게 가능
            // https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0B/solutions/2447.cpp
            if(i%n==1 && j%n==1)continue;
            if(i%n>=box && i%n<2*box && j%n>=box && j%n<2*box) continue;
            if(i==box && j==box) continue;
            else stampstar(i,j,box);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        fill(arr[i],arr[i]+n,' ');
    }

    stampstar(0,0,n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}