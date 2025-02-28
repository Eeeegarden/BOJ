/*
DP인거 어떻게 암?
상담하거나 안하거나 -> O(2^N)
N은 15이하라 2^15 < 33000 완탐 가능할수도?

-테이블
d
-점화식
1. 
이전 날짜중 이익이 가장 큰 것 선택하도록
for(int j=i; j>=0; j--)
    d[i+T[i]] = max(d[j]+P[i], d[i+T[i]]);

2. 1번 처럼 안하고
d[i] = max(d[i], d[i-1]) 로 확정시키고
d[i+T[i]] = max(d[i] + P[i], d[i+T[i]]) 로 j 안쓰고 가능

3. i=n부터 i--
i번째 상담을 했을때랑 안했을때랑 수익중 큰 수익 선택
d[i] = max(d[i+T[i]] + P[i], d[i+1])


*/

#include <bits/stdc++.h>
using namespace std;

int N;
int d[20];
int T[20];
int P[20];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> T[i] >> P[i];
    
        
    for(int i=0; i<N; i++){
        // 퇴사일 넘어가면 continue
        if(i+T[i] >N)continue;
        // 이전 날짜중에서 이익이 큰거 선택
        for(int j=i; j>=0; j--)
            d[i+T[i]] = max(d[j]+P[i], d[i+T[i]]);
    }

    for(int i=0; i<=N; i++) ans = max(ans,d[i]);
    cout << ans;    
}