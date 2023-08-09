// BKD 1번째 O(N)풀이
// 학생이동시 마주하게되는 3가지 상황에따라 체크
// 1. 싸이클OX 체크가 된 학생 재방문시 지금까지 방문한 학생은 싸이클x 학생
// 2. x가 아닌 학생 y 재방문시 y학생이 싸이클 시작점, 즉 그 학생부터 쭉 싸이클o 체크
//    x부터 y 까지는 싸이클x 체크
// 3. x를 재방문시 x는 싸이클o x에서 출발해 x도착시까지 싸이클o 표시
// --> 각 학생을 최대 2번방문 O(N) 으로 풀이가능
// 풀이 : https://blog.encrypted.gg/499
#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int x){
    int cur = x;
    while(1){
        state[cur] = VISITED;
        cur = arr[cur];
        // 1. 싸이클OX 체크가 된 학생 재방문시 지금까지 방문한 학생은 싸이클x 학생
        if(state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN){
            cur = x;
            while(state[cur] == VISITED){
                state[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        // 2. x가 아닌 학생 y 재방문시 y학생이 싸이클 시작점, 즉 그 학생부터 쭉 싸이클o 체크
        //    x부터 y 까지는 싸이클x 체크
        if(state[cur] == VISITED && cur!=x){
            while(state[cur] != CYCLE_IN){
                state[cur]=CYCLE_IN;
                cur = arr[cur];
            }
            cur = x;
            while(state[cur] != CYCLE_IN){
                state[cur] = NOT_CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }            
        // 3. x를 재방문시 x는 싸이클o x에서 출발해 x도착시까지 싸이클o 표시
        if(state[cur] == VISITED && cur == x){
            while(state[cur] != CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
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
        int ans=0;
        for(int i=1; i<=n; i++){
            if(state[i] == NOT_VISITED) run(i);
        }
        int cnt= 0;
        for(int i=1; i<=n; i++){
            if(state[i] == NOT_CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}
    