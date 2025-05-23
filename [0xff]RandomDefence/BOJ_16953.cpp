#include <bits/stdc++.h>
using namespace std;

long long A,B;
int ans=-1;

void fx(int A,int cnt){
    if(A==B){
        ans = cnt+1;
    }
    else if(A>=B)return;
    else{
        fx(A*2, cnt+1);
        if(A<=100000000){
            fx(A*10+1, cnt+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    fx(A,0);

    cout << ans;
}