#include <bits/stdc++.h>
using namespace std;

int N,M;
int vip[42];
int seat[42];
int d[42];
int ans=1;
int cnt=0;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> vip[i];
    }
    
    for(int i=1; i<=N; i++){
        seat[i] = i;
    }
    for(int i=0; i<M; i++){
        seat[vip[i]] = 0;
    }
    d[0] = 1;
    d[1] = 1;
    for(int i=2; i<42; i++){
        d[i] = d[i-2] + d[i-1];
    }

    for(int i=1; i<=N+1; i++){
        if(seat[i]!=0) {
            cnt++;
        }
        else {
            ans*=d[cnt];
            cnt=0;
        }
    }
    
    cout << ans;
}