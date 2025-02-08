// 벡터 내 중복 제거 v.erase(unique(v.begin(), v.end()), v.end());
// 중복 제거 시 벡터 뒤 공백 값으로 들어감

#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> v;

bool cmp(string s1, string s2){
    if(s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()),v.end());

    for(auto c : v) cout << c << '\n';
}