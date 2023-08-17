// 푸는중..
#include <bits/stdc++.h>
using namespace std;

int arr[200002]={0,};
int n,k;
int t=0;
queue<int> Q;
queue<int> Q2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    Q.push(n);

    while(1){
        if(arr[k]!=0){
            cout << arr[k];
            break;
        }
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(k*2<cur)continue;
            if(cur==0){
                Q2.push(cur);
                continue;
            }
            arr[cur]=t;
            cur=cur*2;
            Q.push(cur);
            Q2.push(cur);
        }
        while(!Q2.empty()){
            auto cur = Q2.front(); Q2.pop();
            for(int c: {cur+1,cur-1}){
                if(c>=200002)continue;
                if(c<0)continue;
                if(!arr[c]){
                    arr[c]=t+1;
                    Q.push(c);
                }
            }
        }
        t++;
    }
    

    // for(int i=0; i<=20; i++){
    //     cout << arr[i] << ' ';
    // }
}