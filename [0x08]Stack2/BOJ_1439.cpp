#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(int i=1; i<s.length(); i++){
        if(s[i] != s[i-1]) cnt[s[i] - '0']++; 
    }
    cout << max(cnt[0], cnt[1]);
}