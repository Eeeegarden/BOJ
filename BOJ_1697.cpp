#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int time[200000];
    int N;
    int K;
    int dir[3]={-1,1,2};
    queue<int> Q;

    cin >> N >> K;
    fill(time,time+200000,-1);

    time[N] = 0;
    Q.push(N);

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur == K){
            cout << time[cur] ; 
            break;
        }
        // arange for문 사용하면 코드 줄일수 있음
        for(int i=0; i<2; i++){
            int nx = cur + dir[i];
            if(nx<0 || nx>200000)continue;
            if(time[nx]!=-1)continue;
            time[nx]=time[cur]+1;
            Q.push(nx);
        }
        int nx = cur * 2;
        if(nx>200000)continue;
        if(time[nx]!=-1)continue;
        time[nx]=time[cur]+1;
        Q.push(nx);
    }

}