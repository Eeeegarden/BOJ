/*
테이블 :d[i]
점화식 :값이 작은 항중에 d[j] 가장 큰 값
*/
#include <bits/stdc++.h>
using namespace std;

int A;
int arr[1002];
int d[1002];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A;
    for(int i=0; i<A; i++) {
        cin >> arr[i];
        d[i] = 1;
    }

    for(int i=0; i<A; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]) d[i] = max(d[j]+1, d[i]);
        }
    }
    for(int i=0; i<A; i++) ans = max(d[i], ans);
    cout << ans;

}