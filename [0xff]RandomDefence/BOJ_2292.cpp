#include <bits/stdc++.h>
using namespace std;

int N;
int sum=1;
int ans=1;

void fx(int n, int depth){
    if(sum>=n)return;
    sum += depth * 6;
    ans++;
    fx(n,depth+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fx(N,1);

    cout << ans;
}