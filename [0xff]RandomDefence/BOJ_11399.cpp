#include <bits/stdc++.h>
using namespace std;

int N;
int ans=0;
vector<int> P;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N ;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        P.push_back(num);
    }
    sort(P.begin(), P.end());

    for(int i=0; i<P.size(); i++){
        int sum=0;
        for(int j=0; j<i; j++){
            sum += P[j];
        }
        ans += sum + P[i];
    }
    cout << ans;
}