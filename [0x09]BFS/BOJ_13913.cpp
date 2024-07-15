// 간만에 BFS 감익히기
// 반례 꼼꼼히 생각하기
#include <bits/stdc++.h>
using namespace std;

int N,K;
int dir[2]={-1,1};
queue<int> Q;
stack<int> S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int time[200000];
    int mv[200000];

    cin >> N >> K;
    fill(time,time+200000,-1);
    time[N]=0;
    Q.push(N);


    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur==K){
            cout << time[cur];
            break;
        }
        for(int i=0; i<2; i++){
            int nx = cur + dir[i];
            if(nx<0 || nx>200000)continue;
            if(time[nx]!=-1)continue;
            time[nx]=time[cur]+1;
            mv[nx]=cur;
            Q.push(nx);
        }
        int nx = cur*2;
        if(nx>200000)continue;
        if(time[nx]!=-1)continue;
        time[nx]=time[cur]+1;
        mv[nx]=cur;
        Q.push(nx);
    }
    cout << '\n';
    int i=K;
    while(time[i]!=0){
        S.push(i);
        i=mv[i];
    }
    S.push(i);
    while(!S.empty()){
        cout << S.top() << ' ';
        S.pop();
    }
}