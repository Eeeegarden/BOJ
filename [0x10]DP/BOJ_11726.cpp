// 문제가 DP인지 알기 쉽지 않음

/*
점화식

1. 왼쪽위를 세로로 채우는 경우
- D[n-1]
2. 왼쪽위를 가로로 채우는 경우
- D[n-2]

- > D[n] = D[n-1] + D[n-2]

*/

#include <bits/stdc++.h>
using namespace std;

int D[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    D[1]=1;
    D[2]=2;
    for(int i=3; i<=n; i++) D[i] = (D[i-1] + D[i-2]) % 10007;
    
    cout << D[n];
}
