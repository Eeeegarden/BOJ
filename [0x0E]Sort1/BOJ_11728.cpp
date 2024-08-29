#include <bits/stdc++.h>
using namespace std;

int N,M;
int A[1000002];
int B[1000002];
int tmp[2000004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)cin >> A[i];
    for(int i=0; i<M; i++)cin >> B[i];

    int a=0, b=0;
    for(int i=0; i<N+M; i++){
        if(a==N)tmp[i]=B[b++];
        else if(b==M)tmp[i]=A[a++];
        else if(A[a]<B[b])tmp[i]=A[a++];
        else tmp[i]=B[b++];
    }
    for(int i=0; i<N+M; i++)cout << tmp[i] << ' ' ;

}