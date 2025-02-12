// DP -> 테이블, 점화식, 초기값
/*

f(0) = 1 0
f(1) = 0 1
f(2) = 1 1
f(3) = 1 2
f(4) = 2 3
f(5) = 3 5
f(6) = 5 8

0 :f(n) = f(n-1) + f(n-2)
1 :f(n) = f(n-1) + f(n-2)

*/

#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    int cnt[2][42]={0,};
    cnt[0][0] = 1;
    cnt[1][1] = 1;
    for(int i=0; i<2; i++){
        for(int j=2; j<=40; j++){
            cnt[i][j] = cnt[i][j-1] + cnt[i][j-2];
        }
    }

    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        cout << cnt[0][N] << ' ' << cnt[1][N] << '\n';

    }
}