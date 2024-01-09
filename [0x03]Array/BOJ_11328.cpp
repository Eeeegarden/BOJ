#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    for(int i=0; i<n; i++){
        bool pos=0;
        string s1;
        string s2;
        int aph[26]={0,};
        cin >> s1 >> s2;
        for(int j=0; j<s2.length(); j++){
            aph[s2[j]-'a']++;
            aph[s1[j]-'a']--;
        }
        for(int j=0; j<26; j++){
            if(aph[j]!=0) {
                pos=0;
                break;
            }
            if(j==25) pos=1;
        }
        if(pos==1)cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }
}