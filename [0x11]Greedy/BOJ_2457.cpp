#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
vector<pair<int,int>> arr;
int cur;
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int sm,sd,em,ed;
        cin >> sm >> sd >> em >> ed;
        arr.push_back({sm*100 + sd, em*100 + ed});
    }

    cur = 301;
    while(cur < 1201){
        int nxt = cur;
        for(int i=0; i<N; i++){
            if(arr[i].X <= cur && arr[i].Y > nxt){
                nxt = arr[i].Y;
            }
            if(nxt == cur){
                cout << 0;
                return 0;
            }
            ans++;
            cur = nxt;
        }
        cout << ans;
    }
    




}