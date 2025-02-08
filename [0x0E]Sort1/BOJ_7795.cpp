#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int j=0; j<T; j++){
        int N, M;
        int ans=0;
        int cnt=0;
        cin >> N >> M;
        vector<pair<int,int>> v(N+M);
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            v[i]={a,0};
        }
        for(int i=N; i<N+M; i++){
            int b;
            cin >> b;
            v[i]={b,1};
        }
        sort(v.begin(), v.end());
        for(int i=0; i<N+M; i++){
            if(v[i].Y == 0){
                ans += cnt;
            }
            else cnt++;
        }
        cout << ans << '\n';
    }
}