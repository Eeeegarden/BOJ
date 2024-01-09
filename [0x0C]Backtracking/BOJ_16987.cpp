#include <bits/stdc++.h>
using namespace std;

int n;
int s[302];
int s2[302];
int w[302];
bool isused[302];
int brk=0;
int ans=0;

void func(int k){
    if(k==n){
        for(int i=0; i<n; i++){
            cout << s[i] << ' ';
        }
        cout << '\n';
        if(brk>=ans)ans=brk;
        return;
    }
    if(s[k]<=0)return;
    for(int i=0; i<n; i++){
        if(s[i]<=0 || k==i)continue;
        s[k]-=w[i];
        s[i]-=w[k];
        if(s[k]<0)brk++;
        if(s[i]<0)brk++;
        func(k+1);
        if(s[i]<0)brk--;
        if(s[k]<0)brk--;
        s[i]=s2[i];
        s[k]=s2[k];
    }
}
        

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s[i] >> w[i];
        s2[i]=s[i];
    }
    func(0);

    cout << ans;
}