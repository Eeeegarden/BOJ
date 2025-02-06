// 15m
// 테이블 정의, 점화식 찾기, 초기값 정의하기
#include <bits/stdc++.h>
using namespace std;

int D[1000001];
int X;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X;
    D[1]=0;
    
    for(int i=2; i<=X; i++){
        int x1=INT_MAX,x2=INT_MAX,x3=INT_MAX;
        if(i%3 == 0) x1 = D[i/3]+1;
        if(i%2 == 0) x2 = D[i/2]+1;
        x3 = D[i-1]+1;
        D[i] = min(x1,min(x2,x3));
    }
    cout << D[X];
}