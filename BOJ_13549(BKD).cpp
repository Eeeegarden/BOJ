// Authored by : BaaaaaaaaaaarkingDog

// 덱을 써서 곱하기(front) 후 +-1(back) 해주는 방법이 너무어려웠던 문제
// 우선순위가 곱하기가 먼저 이므로 front에 넣어주고 프론트부터 팝시키면서 계산
// 하기 때문에 작은시간대의 순간이동 계산이 먼저 이루어진다.
#include <bits/stdc++.h>
using namespace std;

int arr[200002];
int MX=200000;
int n,k;
deque<int> dq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(arr,arr+MX,-1);
    dq.push_back(n);
    arr[n]=0;

    while(!dq.empty()){
        auto cur = dq.front(); dq.pop_front();
        if(cur*2<MX && arr[cur*2]==-1){
            arr[cur*2]=arr[cur];
            dq.push_front(cur*2);
        }
        for(auto c : {cur-1,cur+1}){
            if(c<0 || c>=MX || arr[c]!=-1 ) continue;
            arr[c]=arr[cur]+1;
            dq.push_back(c);
        }
    }
    cout << arr[k];


}