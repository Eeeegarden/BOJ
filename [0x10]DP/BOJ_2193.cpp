/*
테이블 정하기

점화식 찾기
100000
= 10 / f(4) + {0000,0100,0010,0001,0101} = (1)0000 의 이친수 = f(5) 

f(n) = f(n-2) + f(n-1)

초기값 정하기
ans[1]=1
ans[2]=1
*/

#include <bits/stdc++.h>
using namespace std;

int N;
long long ans[100]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    ans[1]=1;
    ans[2]=1;

    for(int i=3; i<91; i++){
        ans[i] = ans[i-2] + ans[i-1];
    }

    cout << ans[N];

}