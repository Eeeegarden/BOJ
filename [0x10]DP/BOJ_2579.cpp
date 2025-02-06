// 밟는 계단의 합의 최댓값 -> 안 밟는 계단의 최솟값


// 점화식
/*
10 20 15 25

D[1] = 10 // 안밟음
D[2] = 20 // 1번 밟음
D[3] = 15 // 1번,2번 밟음
D[4] = 35 = S[4] + min(D[i-2],D[i-3]) // 3번밟아야하고 1 OR 2중에 큰거밟아야함 안밟은건 4번, 1 OR 2 중에 작은거

D[k] = S[k] + min(D[k-2],D[k-3]) = 안 밟는 계단의 최솟값


*/

#include <bits/stdc++.h>
using namespace std;

int N;
int st_score[302];
int D[302];
int sum=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> st_score[i];
    }
    for(int i=1; i<=3; i++){
        D[i] = st_score[i];
    }
    for(int i=4; i<=N; i++){
        D[i] = st_score[i] + min(D[i-2],D[i-3]);
    }
    for(int i=1; i<=N; i++)sum+=st_score[i];
    cout << sum - min(D[N-1],D[N-2]);

}