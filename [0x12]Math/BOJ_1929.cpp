#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<bool> state(1000001, true);
vector<int> primes;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;

    state[1] = false;
    for(int i = 2; i*i <= N; i++){
        if(!state[i]) continue;
        for(int j = i*i; j <= N; j += i)
            state[j] = false;
    }
    for(int i = M; i <= N; i++){
        if(state[i]) primes.push_back(i);
    }
    for(auto c : primes) cout << c << '\n'; 
}