// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog

// 항상 1.함수식 2.basecondition 3.재귀식 기반으로 접근
// star가 규칙적으로 찍히면서 startree를 만듬
// 1.함수식 : 별찍기위해선 좌표와 몇개찍을건지 필요 
// 2.basecondition : N이 2씩 나눠지면서 3으로 수렴
// 3.재귀식 : N이 3으로 나눠지면서 새로운 startree 불러옴
#include <bits/stdc++.h>
using namespace std;

char arr[5000][11000];

// 3줄짜리 별 찍기
void star(int row,int col){
    arr[row][col]='*';
    arr[row+1][col-1]='*'; arr[row+1][col+1]='*';
    for(int i=col-2; i<col+3; i++){
        arr[row+2][i]='*';
    }
}

// n에따른 별트리 찍기
void startree(int row,int col,int n){
    if(n==3){
        star(row,col);
        return;
    }
    int ns = n/2;
    startree(row,col,ns);
    startree(row+ns,col-ns,ns);
    startree(row+ns,col+ns,ns);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        fill(arr[i],arr[i]+2*n,' ');
    }

    startree(0,n-1,n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n*2; j++){
            cout << arr[i][j];
        }
        cout <<'\n';
    }
}

