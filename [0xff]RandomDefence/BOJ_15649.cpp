#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[10]={0,};
bool isused[10]={0,};

// 백트래킹 풀이
void fx(int n){
    if(n==M){
        for(int i=0; i<M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++){
        if(!isused[i]){
            arr[n]=i;
            isused[i] = 1;
            fx(n+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fx(0);
}