// 답지쳌...
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,K;
int arr[102];
bool power[102];
vector<int> v;
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=K; i++){
        cin >> arr[i];
    }

    int cur_cnt =0;
    for(int i=1; i<=K; i++){
        int cur = arr[i];
        if(power[cur]) continue;
        if(cur_cnt < N){
            power[cur] = true;
            cur_cnt++;
        }
        else{
            vector<pair<int,int>> idx;
            for(int j=1; j<=K; j++){
                if(!power[j])continue;
                bool vis = false;
                for(int k=i+1; k<=K; k++){
                    if(arr[k] == j){
                        idx.push_back({k,j});
                        vis = true;
                        break;
                    }
                }
                if(!vis) idx.push_back({K+1, j});
            }
            sort(idx.begin(), idx.end(), greater<pair<int,int>>());
            int target = idx[0].Y;
            power[target] = false;
            ans++;
            power[cur] =true;
        }
    }
    cout << ans;
}
