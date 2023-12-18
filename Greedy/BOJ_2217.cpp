#include <bits/stdc++.h>
using namespace std;

int n;
int w;
int arr[100002];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=1; i<=n; i++){
        ans = max(ans,arr[n-i]*i);
    }
    cout << ans;
    
}