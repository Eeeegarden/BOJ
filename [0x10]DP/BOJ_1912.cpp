// 문제보고 DP인거 어떻게 생각함?
// -> n이 작아 전수조사가 가능하다 -> 완탐
// -> 이차원에서 최소시간/경로 -> bfs
// -> n이 커서 전수조사 불가 -> DP

// 1~N 개 연속 셀생각 말고
// N까지 누적합하면서 비교

// DP: 테이블, 점화식, 초기값

/*
-테이블
d[i]

-점화식
1. 이전 연속합이 음수면 버리기 a[i]
d[i] = a[i]
2. 이전 연속합이 0이상이면 가져오기
d[i] = d[i-1] + a[i]

-초기값
d[0] = 0

*/

#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100002];
int d[100002];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    ans = arr[0];

    for(int i=1; i<=N; i++){
        d[i] = max(arr[i-1], d[i-1]+arr[i-1]);
    }

    for(int i=1; i<=N; i++){
        ans = max(ans,d[i]);
    }

    cout << ans;

}