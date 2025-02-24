/*
테이블 
D[i]

점화식 
D[i] = arr[i]보다 작은 값중에 부분수열의 합(D[j])이 가장 큰 것 
*/
#include <bits/stdc++.h>
using namespace std;

int A;
int arr[1002];
int D[1002];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A;
    for(int i=0; i<A; i++) cin >> arr[i];
    D[0]=arr[0];


    for(int i=1; i<A; i++){
        int temp=arr[i];
        // 수열 값이 작은 항중에 -> 증가하는 경우
        // 이전 부분 수열의 합 중 max 값 찾아서 저장
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]) temp = max(temp, D[j]+arr[i]);
        }
        D[i] = temp;
    }
    for(int i=0; i<A; i++) ans = max(ans,D[i]);
    cout << ans;

}