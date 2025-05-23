#include <bits/stdc++.h>
using namespace std;

int N;
int a[10002];
int d[10002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a[i];
        d[i] = a[i];
    }

    d[1] = a[1];
    d[2] = d[1] + a[2];
    
    for(int i=3; i<=N; i++){
        // 1. i안고를떄  2. i,i-1고를때  3. i만 고를때 
        d[i] = max(max(d[i-1], a[i-1]+a[i]+d[i-3]), d[i-2]+a[i]);
    }
    
    cout << d[N];
}