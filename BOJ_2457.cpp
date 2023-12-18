//푸는중


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int sm,sd,em,ed;
int e=1231;
int s=0;
int ans=0;
pair<int,int> f[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> sm >> sd >> em >> ed;
        f[i].Y=sm*100+sd;
        f[i].X=em*100+ed;
    }
    sort(f,f+n);

    // for(int i=0; i<n; i++){
    //     cout << f[i].Y << ' ' << f[i].X << '\n';
    // }

    for(int i=n; i>=0; i--){
        if(f[i].X>=1130 && f[i].X<=e){
            e=f[i].X;
            s=f[i].Y;
        }
    }
    ans++;

    for(int i=n; i>=0; i--){
        if(s<=301)break;
        if(f[i].Y>=s)continue;
        if(f[i].X<s)continue;
        if(f[i].X>s && f[i+1].Y>=f[i].X){
            ans--;
            s=f[i].Y;
            e=f[i].X;
        }
        else {
            s=f[i].Y;
            e=f[i].X;
            ans++;
        }
        cout << s << ' ' << e << '\n';
    }



    cout << ans;
}