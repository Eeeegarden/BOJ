#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> s;
        bool ispalindrome=true;
        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-i-1])ispalindrome=false;
        }
        cout << '#' << tc << ' ' << ispalindrome << '\n';
    }

}