#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<int, int, string>> members;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;
    int age;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        members.push_back({age, i, name});
    }
    sort(members.begin(), members.end());
    
    for (auto [age, _, name] : members){
        cout << age << " " << name << '\n';
    }
}