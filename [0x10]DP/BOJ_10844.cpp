/*
N 100자리 -> DP

테이블 d[자릿수][끝자리]

점화식
d[i][j] = d[i-1][j-1] + d[i-1][j+1]

두자릿수면 일의자릿수로 결정
-> 1~8까지는 2개 9는 1개 = 17

세자리면 십의자릿수로 결정
-> 10인경우 101 -> 1개 
-> 89인경우 898 -> 1개
-> 나머지 45인경우 456, 454 -> 2개

끝자리 기준으로 카운팅

*/

#include <bits/stdc++.h>
using namespace std;
#define modn 1000000000
int N;
long long d[102][102];
long long ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    d[1][0] = 0;
    for(int i=1; i<=9; i++) d[1][i] = 1;

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            if(j==0) d[i][j] = d[i-1][j+1] % modn;
            else if(j==9) d[i][j] = d[i-1][j-1] % modn;
            else d[i][j] = d[i-1][j-1] + d[i-1][j+1] % modn;
        }
    }

    for(int i=0; i<=9; i++) ans += d[N][i] % modn;
    cout << ans % modn;


}