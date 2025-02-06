/*
점화식

D[i] = A[1] + A[2] + ... A[i]
D[i] = D[i-1] + A[i]

A[i] + A[i+1] ... +A[j]
= (A[1] + A[2] ... + A[j]) - (A[1] + A[2] + ... A[i-1])
= D[j] - D[i-1]
*/

#include <bits/stdc++.h>
using namespace std;

int arr[100002];
int st[100002];
int ed[100002];
int D[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=M; i++){
        cin >> st[i] >> ed[i];
    }
    for(int i=1; i<=N; i++) D[i] = D[i-1] + arr[i];
    
    for(int i=1; i<=M; i++){
        cout << D[ed[i]] - D[st[i]-1] << '\n';
    }
}