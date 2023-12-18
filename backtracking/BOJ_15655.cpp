#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int num[10];
bool isused[10];

void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(!isused[i]){
            if(num[i-1]<arr[k-1])continue;
            isused[i]=1;
            arr[k]=num[i-1];
            func(k+1);
            isused[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    sort(num,num+n);
    func(0);
}