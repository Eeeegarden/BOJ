#include <bits/stdc++.h>
using namespace std;

int n;
int a[52];
int b[52];
int c[52];
int ans=0;

bool desc(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    copy(b,b+n,c);
    sort(a,a+n);
    sort(c,c+n,desc);

    for(int i=0; i<n; i++){
        ans+=a[i]*c[i];
    }
    cout << ans;
}

