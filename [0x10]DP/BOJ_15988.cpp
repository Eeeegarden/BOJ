#include <bits/stdc++.h>
using namespace std;

int T;
int a[1000002];
long long d[1000002];
long long DIV = 1000000009;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> a[i];
    }
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for(int i=4; i<1000002; i++){
        d[i] = ((d[i-3]%DIV)+(d[i-2]%DIV)%DIV)+(d[i-1]%DIV)%DIV;
    }

    for(int i=0; i<T; i++){
        cout << d[a[i]] % DIV << '\n';
    }
}