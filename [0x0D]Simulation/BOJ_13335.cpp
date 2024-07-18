//푸는중
#include <bits/stdc++.h>
using namespace std;

int n,w,L;
int a[12]={0,};
int dis[1002]={0,};
int ans=0;

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
    // 다리 하중보다 트럭무게가 작으면서
    // 마지막 트럭까지 다 지나갈때까지
    
    while(dis[n-1]!=0){
        int curw=0;
        for(int i=0; i<n; i++){
            if(dis[i]==0)continue;
            if(curw+dis[i]>L)continue;
            if(dis[i]>0 && dis[i]<w){
                curw+=a[i];
                dis[i]--;
                if(dis[i]==0)curw-=a[i];
            }
            // 다리 하중 0일때 트럭움직이는거 추가하기
        }
        for(int i=0; i<n; i++){
                cout << dis[i] << ' ';
        }
        cout << '\n';
        ans++;
    }
    cout << ans;
}







