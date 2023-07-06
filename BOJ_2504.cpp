// 분배법칙 이용 어렵
// 괄호를 닫을때 tmp를 나눠주면서 파라미터를 만든다

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string a;
    int tmp=1;
    int ans=0;
    bool check_err = false;

    cin >> a;

    for(int i=0; i<a.length(); i++){
        if(a[i]=='('){
            s.push(a[i]);
            tmp*=2;
        }
        if(a[i]=='['){
            s.push(a[i]);
            tmp*=3;
        }
        else if(a[i]==')'){
            if(s.empty()){
                check_err=true;
                break;
            }
            if(s.top()=='('){
                if(a[i-1]=='(')ans+=tmp;
                s.pop();
                tmp/=2;
            }
            else {
                check_err=true;
                break;
            }
        }
        else if(a[i]==']'){
            if(s.empty()){
                check_err=true;
                break;
            }
            if(s.top()=='['){
                if(a[i-1]=='[')ans+=tmp;
                s.pop();
                tmp/=3;
            }
            else{
                check_err=true;
                break;
            }
        }
    }

    if(check_err==true || !s.empty()){
        cout << '0' ;
    }
    else cout << ans;
}
