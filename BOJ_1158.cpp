#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    list<int> L={};
    list<int> Y={};

    for(int i=1; i<=n; i++){
        L.insert(L.end(),i);
    }

    auto cursor=L.begin();

    while(n--){
        for(int i=0; i<k-1; i++){
            if(cursor == L.end())cursor=L.begin();
            else cursor++;
            if(cursor == L.end())cursor=L.begin();
        }
        Y.push_back(*cursor);
        cursor = L.erase(cursor);
        if(cursor == L.end())cursor=L.begin();

    }

    for(auto c : Y){
        if( c == Y.front())cout << '<' ; 
        cout << c ;
        if( c != Y.back())cout << ", ";
        else cout << '>';
    }
}