#include <bits/stdc++.h>
using namespace std;

int T;
int a[10002][1002];
int cnt[10002][102]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        int test_num;
        int mx = 0;
        int mx_idx;
        cin >> test_num;
        // 1000명 받아서 점수배열++
        for(int j=0; j<1000; j++){
            cin >> a[i][j];
            cnt[i][a[i][j]]++;
        }
        for(int j=0; j<100; j++){
            if(cnt[i][j]>=mx) {
                mx = cnt[i][j];
                mx_idx = j;
            }
        }
        
        cout << '#' << test_num << ' ' << mx_idx << '\n';
    }
}