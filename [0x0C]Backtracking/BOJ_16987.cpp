// 백트래킹 풀이참조..
// 백트래킹 시 함수형태 무조건 void로
#include <bits/stdc++.h>
using namespace std;

int N;
int s[10];
int w[10];
int ans=0;
int cnt=0;

void solve(int n){
    // 백트래킹 종료
    if(n==N){
        ans=max(cnt,ans);
        return;
    }
    // 계란이 이미 깨져있거나 남은 계란 모두가 깨져있을때
    if(s[n]<=0 || cnt==N-1){
        solve(n+1);
        return;
    }
    for(int dir=0; dir<N; dir++){
        if(dir==n || s[dir]<=0)continue;
        s[n]-=w[dir];
        s[dir]-=w[n];
        if(s[n]<=0)cnt++;
        if(s[dir]<=0)cnt++;
        solve(n+1);
        if(s[n]<=0)cnt--;
        if(s[dir]<=0)cnt--;
        s[n]+=w[dir];
        s[dir]+=w[n];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s[i] >> w[i];
    }
    solve(0);

    cout << ans;
}