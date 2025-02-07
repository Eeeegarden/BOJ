// 테이블, 점화식, 초기값

// 경로 저장하는 테이블 추가

/*
점화식


D[i] = D[i-1] + 1
if(i%3==0) D[i] = D[i/3] + 1
if(i%2==0) D[i] = D[i/2] + 1
*/

#include <bits/stdc++.h>
using namespace std;

int D[1000001];
int PRE[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    D[1]=0;
    PRE[1]=0;

    for(int i=2; i<=N; i++){
        D[i] = D[i-1] +1;
        PRE[i] = i-1;
        if(i%3==0 && D[i]>D[i/3]+1) {
            D[i] = D[i/3] + 1;
            PRE[i] = i/3;
        }
        if(i%2==0 && D[i]>D[i/2]+1) {
            D[i] = D[i/2] + 1;
            PRE[i] = i/2;
        }
    }
    cout << D[N] << '\n';
    cout << N << ' ';
    for(int i=N; PRE[i]>=1; i=PRE[i]){
        cout << PRE[i] << ' ';
    }
}