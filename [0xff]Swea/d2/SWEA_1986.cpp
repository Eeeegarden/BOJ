#include <bits/stdc++.h>
using namespace std;

int T;
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> N;
        int ans=0;
        for(int i=1; i<=N; i++){
            if(i%2==1) ans+=i;
            else ans-=i;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}