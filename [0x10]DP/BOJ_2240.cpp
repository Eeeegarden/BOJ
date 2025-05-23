#include <bits/stdc++.h>
using namespace std;

int tree[1002];
int d[1002][32]={0,};
int T,W;
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> W;

    for(int i=1; i<=T; i++){
        cin >> tree[i];
    }

    // 만약 한번도 안움직이는경우
    int cnt=0;
    for(int i=1; i<=T; i++){
        if(tree[i] == 1) cnt++;
        d[i][0]=cnt;
    }

    // 1 ~ 모두 움직임까지의 개수를 카운트
    for(int i=1; i<=T; i++){
        for(int j=1; j<=W; j++){
            if(j>i)break;
            if((tree[i]==1 && (j%2==0)) || (tree[i]==2 && (j%2==1))){
                d[i][j] = max(d[i-1][j-1],d[i-1][j]) + 1;
            }
            else d[i][j] = max(d[i-1][j-1], d[i-1][j]);
        }
    }

    for(int i=0; i<=T; i++){
        for(int j=0; j<=W; j++){
            if(d[i][j]>=ans)ans = d[i][j];
        }
    }

    cout << ans;
}