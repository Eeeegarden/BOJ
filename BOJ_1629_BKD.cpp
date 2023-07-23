//Autored by : BaaaaaaaaaaarkingDog
//귀납적사고 넘어렵 base condition, k승계산가능->2k,2k+1이 O(1)로 계산가능
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fx(ll a,ll b,ll c){
    if(b==1) return a % c;
    ll val = fx(a,b/2,c);
    val = val * val % c;
    if(b%2==0) return val;
    return val * a % c;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c;
    cin >> a >> b >> c;
    cout << fx(a,b,c);
}