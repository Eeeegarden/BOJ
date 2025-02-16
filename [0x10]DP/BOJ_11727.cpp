// 테이블, 점화식, 초기값

/*
테이블

점화식
왼쪽 위

1*2
f(n) = f(n-1)
2*1
f(n) = f(n-2)
2*2
f(n) = f(n-2)

초기값
f(0) = 0
f(1) = 1
f(2) = 3


*/ 

#include <bits/stdc++.h>
using namespace std;

int n;
int ans[1002]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 3;

    for(int i=3; i<=n; i++){
        ans[i] = ans[i-1]%10007 + (2*ans[i-2])%10007;
    }
    cout << ans[n]%10007;

}