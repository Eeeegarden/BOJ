#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> s;

int fx(int c, int t = 0) {
    if (c == 1) {
        s.push(t);
        return -2;
    }
    else if (c == 2) {
        if (s.empty()) return -1;
        int k = s.top(); s.pop();
        return k;
    }
    else if (c == 3) {
        return s.size();
    }
    else if (c == 4) {
        return s.empty();
    }
    else if (c == 5) {
        if (s.empty()) return -1;
        return s.top();
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int t;
            cin >> t;
            fx(c, t);
        } else {
            cout << fx(c) << '\n';
        }
    }
}
