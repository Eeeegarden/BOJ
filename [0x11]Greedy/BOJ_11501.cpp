#include <bits/stdc++.h>
using namespace std;

int T;
int N;
int s_p[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=0; tc<T; tc++){
        long long ans=0;
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> s_p[i];
        }
        int h_price=s_p[N-1];
        for(int i=N-2; i>=0; i--){
            if(s_p[i] > h_price) h_price = s_p[i];
            ans += h_price - s_p[i];
        }
        cout << ans << '\n';
    }
}