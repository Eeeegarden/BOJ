#include <bits/stdc++.h>
using namespace std;

int N;
int ans;
deque<int> d;

int card(deque<int> d){
    int temp;
    while(d.size() > 1){
        d.pop_front();
        temp = d.front();
        d.pop_front();
        d.push_back(temp);
    }
    return d.front();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++){
        d.push_back(i);
    }
    ans = card(d);
    
    cout << ans;
}