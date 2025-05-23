#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++){
        int cnt=0;
        int temp=i;
        while(temp>0){
            if(temp%10 == 3)cnt++;
            if(temp%10 == 6)cnt++;
            if(temp%10 == 9)cnt++;
            temp/=10;
        }

        if(cnt!=0){
            for(int j=0; j<cnt; j++){
                cout << "-";
            }
            cout << ' ';
        }
        else cout << i << ' ';
    }
}