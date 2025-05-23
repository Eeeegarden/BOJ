#include <bits/stdc++.h>
using namespace std;

int n;
long long fib[92]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fib[0]=0;
    fib[1]=1;
    for(int i=2; i<=n; i++){
        fib[i]=fib[i-1]+fib[i-2];
    }

    cout << fib[n];
}