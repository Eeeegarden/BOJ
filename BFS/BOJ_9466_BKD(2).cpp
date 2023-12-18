// BKD 2번째 풀이
// 1번풀이 케이스를 줄임 
// state 값을 VISIED 대신 x 값으로표시함으로써 간결해짐
// state 값이 NOT_VISITED 이 아니면 패스 (1번케이스에해당)

#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int state[100005];
int n;

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
    int cur = x;
    while(1){
        // 방문체크
        state[cur]=x;
        cur=arr[cur];
        // 사이클 체크
        if(state[cur]==x){
            while(state[cur]!=CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur=arr[cur];
            }
            return;
        }
        // 1번케이스
        else if(state[cur]!=0) return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fill(state+1,state+1+n,0);
        for(int i=1; i<=n; i++){
            cin >> arr[i];
        }
        for(int i=1; i<=n; i++){
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}
