#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

bool comp(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N>0){
        v.push_back(N%10);
        N/=10;
    }
    
    sort(v.begin(),v.end(),comp);
    for(int i=0; i<v.size(); i++){
        cout << v[i];
    }
}