#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    int q;
    cin >> S;
    list<char> L;

    for(auto c : S){
        L.push_back(c);
    }
    auto cursor = L.end();
    cin >> q;

    while(q--){
        char op;
        cin >> op;
        if(op == 'P'){
            char op2;
            cin >> op2;
            L.insert(cursor,op2);
        }
        else if(op == 'L'){
            if(cursor != L.begin())cursor--;
        }
        else if(op == 'D'){
            if(cursor != L.end())cursor++;
        }
        else if(op == 'B'){
            if(cursor != L.begin()){
                cursor--;
                cursor=L.erase(cursor);
            }
        }
    }
    for(auto c: L){
        cout << c;
    }
}