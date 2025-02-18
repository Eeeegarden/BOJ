#include <bits/stdc++.h>
using namespace std;

int N;
string s[102];
int ans=0;

bool isgroup(string temp){
    int apb[26]={0,};
    
    for(int i=0; i<temp.length(); i++){
        char cur = temp[i];
        // 나온적 없는 단어일때
        if(apb[cur -'a'] == 0){
            apb[cur -'a']++;
            while(i+1 < temp.length() && cur == temp[i+1]) i++;
        }
        else return false;
    }
    return true;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int j=0; j<N; j++){
        cin >> s[j];
        if(isgroup(s[j]))ans++;
    }
    cout << ans;

}