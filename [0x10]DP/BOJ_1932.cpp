// 테이블, 점화식, 초깃값
// 전체 다 계산하면 2^n -> 2 500제곱;

// 누적합 시키면서 내려가면댐 -> O(n) 해결가능
/*
sum[0][0] = board[0][0] 초기값
sum[1][0] = board[0][1]
.. 
sum[2][1] = board[2][1] + max(sum[1][0], sum[1][1]); 
큰거 골라서 누적합 

*/

#include <bits/stdc++.h>
using namespace std;

int n;
long long board[501][501];
long long sum[501][501]={0,};
long long ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> board[i][j];
        }
    }
    sum[0][0]=board[0][0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            sum[i][j] = board[i][j] + max(sum[i-1][j-1], sum[i-1][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, sum[i][j]);
        }
    }

    cout << ans;
}