#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
vector<pair<int,int>> T;
int cur_lec[200002]={0,};
int ans=0;
int cur=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        T.push_back({x,1});
        T.push_back({y,-1});
    }
    sort(T.begin(), T.end());

    for(int i=0; i<T.size(); i++){
        int time = T[i].X;
        int type = T[i].Y;
        cur += type; 
        ans = max(ans, cur); 
    }
    cout << ans;
}