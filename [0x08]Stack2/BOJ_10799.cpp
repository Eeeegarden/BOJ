#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    int ans=0;
    string a;

    cin >> a;

    // ')' 의미하는게 레이저인지 막대기 끝인지 확인해서 풀이
    // 레이저 발생시 스택의 사이즈활용
        for(int i=0; a[i]!='\0'; i++){
        if(a[i]=='(')s.push(a[i]);
        else if(a[i]==')'){
            if(a[i-1]=='('){
                s.pop();
                ans+=s.size();
            }
            else if(!s.empty() && a[i-1]==')'){
                s.pop();
                ans++;
            }
        }
    }
    cout << ans;

}
