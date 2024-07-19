// 2H 20M
// 구현은 금방했는데
// a값 범위설정 잘못해서(a[10]으로 설정해서 뻘짓함)

#include <bits/stdc++.h>
using namespace std;

int n,w,L;
int a[1002]={0,};
int dis[1002]={0,};
int ans=0;
int curi=0;
queue<int> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        dis[i]+=w+i+1;
    }

    // 맨앞트럭 curi로 설정하면서 차례로 계산
    while(curi<n){
        int curw=0;
        for(int i=curi; i<n; i++){
            if(dis[i]==0)continue;
            if(dis[i]<=w){
                curw+=a[i];
                dis[i]--;
                if(dis[i]==0){
                    curi=i+1;
                    curw-=a[i];
                }
            }
            else{
                if(dis[i]-1==w){
                    if(curw+a[i]>L)break;
                    curw+=a[i];
                    dis[i]--;
                }
                else dis[i]--;
            }
        }
        ans++;
    }
    cout << ans;
}