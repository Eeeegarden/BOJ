#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
pair<int,int> arr[100002];
int ans=0;
int t=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i].Y >> arr[i].X;
    }
    sort(arr,arr+n);

    for(int i=0; i<n; i++){
        if(t>arr[i].Y)continue;
        t=arr[i].X;
        ans++;
    }
    cout << ans;
}
