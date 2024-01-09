// 처음에 2의20제곱이라 시간초과가 걸릴줄알고
// 양수음수 나눠서 계산을하려했으나 
// 2의20제곱이면 백만밖에 안되니 그냥 풀어도되는듯

#include <bits/stdc++.h>
using namespace std;

int n,s;
int arr[25];
int ans=0;

void func(int cur, int num){
    if(cur==n){
        if(num==s)ans++;
        return;
    }
    func(cur+1,num);
    func(cur+1,num+arr[cur]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }
    func(0,0);
    if(s==0)ans--;
    cout << ans;

}
