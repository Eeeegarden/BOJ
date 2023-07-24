#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v;
    int arr[201]={0,};

    cin >> n;

    while(n--){
        int i;
        cin >> i;
        arr[i+100]++;
    }

    cin >> v;

    cout << arr[v+100];
}