// 21m
// 테이블, 점화식, 초기값

// 점화식
/*
i, i+1 다른색이면서 최솟값
- 2번째 집의 최솟값 
R : D[2][0] = R[2] + min(D[1][1], D[1][2])
G : D[2][1] = G[2] + min(D[1][0], D[1][2])
B : D[2][2] = B[2] + min(D[1][0], D[1][1])

-> 
*/

#include <bits/stdc++.h>
using namespace std;

int R[1002];
int G[1002];
int B[1002];
int D[1002][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> R[i] >> G[i] >> B[i];
    } 
    D[1][0] = R[1];
    D[1][1] = G[1];
    D[1][2] = B[1];

    for(int i=2; i<=N; i++){
        D[i][0] = R[i] + min(D[i-1][1], D[i-1][2]);
        D[i][1] = G[i] + min(D[i-1][0], D[i-1][2]);
        D[i][2] = B[i] + min(D[i-1][0], D[i-1][1]);
    }

    cout << min(D[N][0],min(D[N][1],D[N][2]));

}