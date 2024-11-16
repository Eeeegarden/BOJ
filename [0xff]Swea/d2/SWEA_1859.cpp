#include <bits/stdc++.h>
using namespace std;

int test_case;
long long arr[1000002];
int n;
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int max_d=0, max_p=0;
        long long p_sum=0;
        cin >> n; 
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        int cur = 0;

        while(cur<n){
            max_d=0; max_p=0, cnt=0;
            // 최대 이득 구간 찾기
            for(int j=cur; j<n; j++){
                if(arr[j]>=max_p){
                    max_p=arr[j];
                    max_d=j;
                }
            }

            // 수익 계산
            for(int j=cur; j<=max_d; j++){
                if(j==max_d) p_sum += arr[j] * cnt;
                else p_sum -= arr[j];
                cnt++;
                cur++;
            }
        }
        cout << "#" << i+1 << ' ' << p_sum << '\n';
    }
}