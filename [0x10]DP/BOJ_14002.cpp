#include<bits/stdc++.h>
using namespace std;

int N;
int a[1002];
int d[1002];
int mx_str = 1;
stack<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> a[i];
        d[i] = 1;
    }

    for(int i=1; i<=N; i++){            
        for(int j=1; j<=i; j++){
            if(a[i]>a[j]) {
                d[i] = max(d[j]+1, d[i]);
                if(d[i]>mx_str) mx_str=d[i];
            }
        }
    }

    for(int i=N; i>0; i--){
        if(d[i]==mx_str){
            ans.push(a[i]);
            mx_str--;
        }
    }

    cout << ans.size() << '\n';
    while(!ans.empty()){
        cout << ans.top() << ' ' ;
        ans.pop();
    }

    cout << '\n';
}