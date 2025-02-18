#include <bits/stdc++.h>
using namespace std;

int T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        int j=0;
        stack<char> s;
        string PS;
        cin >> PS;
        for(; j<PS.length(); j++){
            if(PS[j] == '(')s.push(PS[j]);
            if(PS[j] == ')'){
                if(s.empty()) {
                    cout << "NO" << '\n';
                    break;
                }
                s.pop();
            }
        }
        if(j==PS.length() && s.empty()) cout << "YES" << '\n';
        else if(j==PS.length() && !s.empty()) cout << "NO" << '\n';
        else continue;
    }
}