#include <bits/stdc++.h>
using namespace std;

int apb[30]={0,};
string s;
char ans;
int ans_index;
int mx=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;

    for(int i=0; i<s.length(); i++){
        s[i] = tolower(s[i]);
        apb[s[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(mx < apb[i]) {
            mx = apb[i];
            ans_index = i;
        }
    }
    for(int i=0; i<26; i++){
        if(i==ans_index)continue;
        if(mx == apb[i]){
            cout << "?" ;
            return 0;
        }
    }
    ans = ans_index + 'A';
    cout << (char)ans;

}