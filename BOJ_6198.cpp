#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans=0;
    stack<int> s;

    cin >> n;

    while(n--){
        long long h;
        cin >> h;
        // 아래 계산식 생각하기 어려움
        while(!s.empty() && s.top()<=h)
            s.pop();
        ans+=s.size();
        s.push(h);
    }
    cout << ans;
}

