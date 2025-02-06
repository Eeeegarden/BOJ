// 16m

// 점화식
/* D[4] 분해
1+1+1+1 1+2+1 3+1 2+1+1 D[3]에 +1
1+1+2 2+2 D[2]에 +2
1+3 D[1]에 +3
*/

// 위 식으로 D[4] = D[3] + D[2] + D[1] 도출
// D[i] = D[i-1] + D[i-2] + D[i-3]


#include <bits/stdc++.h>
using namespace std;

int T;
int D[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    D[0]=0,D[1]=1,D[2]=2,D[3]=4;

    for(int i=4; i<11; i++){
        D[i] = D[i-1] + D[i-2] + D[i-3];
    }

    for(int i=0; i<T; i++){
        int n;
        cin >> n;
        cout << D[n] << '\n';
    }
}