#include <bits/stdc++.h>
using namespace std;

int T;
int N;

bool chk_a(bool a[10]){
    for(int i=0; i<10; i++){
        if(!a[i])return false;
    }
    return true;
}

int cal_dig(int N){
    int a = 1000000;
    int cnt=7;
    while(N<a){
        a/=10;
        cnt--;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> N;
        bool a[10]={0,};
        int temp_N = N;
        while(!chk_a(a)){
            int digit = cal_dig(temp_N);
            int temp = temp_N;
            for(int i=0; i<digit; i++){
                int num = temp%10;
                a[num]=1;
                temp/=10;
            }
            if(!chk_a(a))temp_N+=N;
        }
        cout << '#' << tc << ' ' << temp_N << '\n';
    }
}