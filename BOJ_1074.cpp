// 1.함수의 정의 2.base condition 3.재귀 식
// 푸는중
#include <bits/stdc++.h>
using namespace std;

int func(int n,int r,int c){
    if(n==0)return 0;
    //1번
    if(n>r && n>c)return func(n-1,r,c);
    //2번
    if(n>r && n<=c)return func(n-1,r,c-n)+n*n;
    //3번
    if(n<=r && n>c)return func(n-1,r-n,c)+n*n*2;
    //4번
    if(n<=r && n<=c)return func(n-1,r-n,c-n)+n*n*3;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r,c;

    cin >> n >> r >> c;
    cout << func(n,r,c);

}
