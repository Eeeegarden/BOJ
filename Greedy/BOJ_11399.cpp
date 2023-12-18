#include <bits/stdc++.h>
using namespace std;

int n;
int p[1002];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p,p+n);

    // for (int i = 0; i < N; i++) ans += P[i] * (N - i); 
    // 같이 간단하게 한줄로 구현가능 .. 수학열심히..

    for(int i=0; i<n; i++){
        int t=i;
        int sum=0;
        while(t>=0){
            sum+=p[t];
            t--;
        }
        ans+=sum;
    }
    cout << ans;
}