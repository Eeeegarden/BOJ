// 방문했던 노드를 또 방문하는 알고리즘 O(n^2)으로 시간초과발생

#include <bits/stdc++.h>
using namespace std;


int stu[100002];
int vis[100002];
int t,n;
queue<int> Q;
bool check_cycle = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int tc=0; tc<t; tc++){
        int cnt=0;
        cin >> n;
        fill(vis,vis+n,0);
        for(int i=0; i<n; i++){
            cin >> stu[i];
            if(stu[i]==i+1) vis[i]=1;
        }

        for(int i=0; i<n; i++){
            if(vis[i]==0){
                Q.push(stu[i]);
            }
            else continue;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                int dir = stu[cur-1];
                if(check_cycle==1 && vis[dir-1]==0){
                    vis[dir-1]++;
                    Q.push(stu[dir-1]);
                }
                else if(check_cycle==1 && vis[dir-1]==1){
                    check_cycle=0;
                    continue;
                }
                else if(vis[dir-1]!=0) continue;
                else if(dir==i+1){
                    vis[dir-1]++;
                    Q.push(stu[dir-1]);
                    check_cycle=1;
                }
                else if(dir-1!=i)Q.push(stu[dir-1]);
            }
        }
        for(int i=0; i<n; i++){
            if(vis[i]==0)cnt++;
        }
        cout << cnt << '\n';
    }
}