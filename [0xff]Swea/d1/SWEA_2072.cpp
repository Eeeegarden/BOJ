#include <bits/stdc++.h>
using namespace std;

int T;
int a[1000002][12];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        int ans=0;
        for(int j=0; j<10; j++){
            cin >> a[i][j];
        }
        for(int j=0; j<10; j++){
            if(a[i][j]%2==1)ans+=a[i][j];
        }
        cout << '#' << i+1 << ' '<<  ans << '\n';
    }


}