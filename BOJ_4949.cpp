#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    vector<string> v;
    stack<char> s;
    int i;

    while(str[0]!='.'){
        while(!s.empty())s.pop();
        getline(cin,str);
        for(i=0; str[i]!='\0'; i++){
            if(str[i]=='(' || str[i]=='[')s.push(str[i]);
            else if(str[i]==')'){
                if(s.empty() || s.top()!='('){
                    s.push(str[i]);
                    break;
                }
                s.pop();
            }
            else if(str[i]==']'){
                if(s.empty() || s.top()!='['){
                    s.push(str[i]);
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty())v.push_back("no\n");
        else if(str[0]=='.')break;
        else v.push_back("yes\n");
    }
    for(auto c : v)cout << c;
}