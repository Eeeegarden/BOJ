#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[12];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=n-1; i>=0; i--){
        if(arr[i]>k)continue;
        while(arr[i]<=k){
            k-=arr[i];
            ans++;
        }
    }

    cout << ans;
}