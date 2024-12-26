// 백트래킹 어렵다....
// 자릿수보다 교환 횟수 많은경우 -> 에러

#include <bits/stdc++.h>
using namespace std;

int test_case;
int rep_cnt;
int num;
int digit;
int max_n=0;
int isused[102][102];

void func(int cur_cnt, deque<int> cpy_D){
    if(cur_cnt==rep_cnt) {
        int cur=0;
        int cnt=1;
        for(int i=digit-1; i>=0; i--){
            cur += cpy_D[i] * cnt;
            cnt*=10;
        }
        max_n=max(cur,max_n);
        return;
    }
    for(int i=0; i<digit; i++){
        for(int j=i+1; j<digit; j++){
            swap(cpy_D[i], cpy_D[j]); 
            func(cur_cnt+1, cpy_D);
            swap(cpy_D[i], cpy_D[j]);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;

    for(int i=0; i<test_case; i++){
        deque<int> D;
        int rep=100000;
        digit = 0;
        cin >> num >> rep_cnt;
        
        for(int j=0; j<6; j++){
            if(num/rep!=0 || digit>0){
                D.push_back(num/rep);
                num%=rep;
                digit++;
            }
            rep/=10;
        }
        max_n=0;
        deque<int> cpy_D(D);
        func(0,cpy_D);
        cout << "#" << i+1 << ' ' << max_n << '\n';
        
    }
}
