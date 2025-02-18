#include <bits/stdc++.h>
using namespace std;

int K;
long long ans=0;
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    for(int i=0; i<K; i++){
        int num;
        cin >> num;
        if(num == 0)s.pop();
        else s.push(num);
    }

    while(!s.empty()){
        ans += s.top(); s.pop();
    }

    cout << ans;
}