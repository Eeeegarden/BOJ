#include <bits/stdc++.h>
using namespace std;

// 범위에 0하나 빼먹어서 런타임에러 발생; 잘 확인하기
int dis[1000002];
int f,s,g,u,d;
queue<int> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d ;
    fill(dis+1,dis+f+1,-1);
    Q.push(s);
    dis[s]=0;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        // for(auto c : {cur+u, cur-d}) 로 하면 조금 더 간결한코드가능
        for(int i=0; i<2; i++){
            if(i==0){
                int nu = cur + u;
                if(nu>f) continue;
                if(dis[nu]!=-1) continue;
                dis[nu]=dis[cur]+1;
                Q.push(nu);
            }
            else{
                int nd = cur - d;
                if(nd<=0) continue;
                if(dis[nd]!=-1) continue;
                dis[nd]=dis[cur]+1;
                Q.push(nd);
            }
        }
    }

    if(dis[g]!=-1) cout << dis[g];
    else cout << "use the stairs";

}