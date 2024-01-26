// N범위가 1,000,000 -> 일반적으로 탐색하면 시간초과 발생
// stack으로 s.top()이용하여 비교

#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000002];
int ans[1000002];
stack<int> S;
int cnt=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=N-1; i>=0; i--){
        // 비거나 S.top()이 더 클때까지 S.pop()하는게 핵심
        while(!S.empty() && S.top()<=A[i])S.pop();
        if(S.empty())ans[i]=-1;
        else ans[i]=S.top();
        S.push(A[i]);
    }
    for(int i=0; i<N; i++){
        cout << ans[i] << ' ';
    }
}