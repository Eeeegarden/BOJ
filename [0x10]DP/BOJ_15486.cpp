// BOJ_14501와 풀이는 동일

// 14501의 2,3 풀이 쓰면 cnt 안쓰고 가능
#include <bits/stdc++.h>
using namespace std;

int N;
int T[1500002];
int P[1500002];
long long d[1500002];
long long ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=0; i<N; i++){
        if(i+T[i]>N)continue;
        int cnt=0;
        // N이 크기때문에 2중 for문쓰면 시간초과 날 확률 높음
        // 1 ≤ Ti ≤ 50 이기 때문에 최대 50번
        for(int j=i; j>=0; j--){
            if(cnt>52)break;
            d[i+T[i]] = max(d[j]+P[i], d[i+T[i]]);
            cnt++;
        }
    }

    for(int i=0; i<=N; i++) ans = max(ans,d[i]);
    cout << ans;
}