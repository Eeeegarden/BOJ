#include <bits/stdc++.h>
using namespace std;

int N,K;
int arr[12];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=N-1; i>=0; i--){
        if(K>=arr[i]){
            while(K>=arr[i]){
                K-=arr[i];
                ans++;
            }
        }
    }
    cout << ans;
}