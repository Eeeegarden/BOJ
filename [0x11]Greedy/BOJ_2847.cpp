#include <bits/stdc++.h>
using namespace std;

int N;
int score[102];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> score[i];

    for(int i=N-1; i>0; i--){
        while(score[i-1] >= score[i]){
            score[i-1]--;
            ans++;
        }
    }
    cout << ans;
}