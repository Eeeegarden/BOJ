#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int ans=0;
    int last_op = 1;
    string tmp;
    
    for(int i=0; i<=s.length(); i++){
        if(s[i] == '-' || s[i] == '+' || i == s.length()){
            ans += stoi(tmp) * last_op;
            if(s[i] == '-') last_op = -1;
            tmp = "";
        }
        else{
            tmp += s[i];
        }

    }
    cout << ans;
}