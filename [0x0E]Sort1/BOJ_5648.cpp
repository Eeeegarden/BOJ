// string 관련 함수 알아두기
// + stoi = string to integer

#include<bits/stdc++.h>
using namespace std;

string st;
vector<long long> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> st;
        reverse(st.begin(), st.end());
        v.push_back(stoll(st));
    }
    sort(v.begin(),v.end());
    for(auto c : v){
        cout << c << '\n';
    }

}