// 1H30M

// 인덱스에 해당하는 연산자를 순열돌리기위해 line:33~38 과정 있었음
// 생각보다 생각하기 어려웠던문제

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
#define MIN -1000000000

int N;
int arr[13];
int opt[4];
int opt_sum=0;
int ans_max=MIN;
int ans_min=MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> opt[i];
        opt_sum+=opt[i];
    }

    // 연산자에 해당하는 인덱스를 배열에 갯수만큼 삽입
    // 순열돌리기위함
    vector<int> tmp;
    for(int i=0; i<4; i++){
        int cnt=opt[i];
        if(opt[i]==0)continue;
        else while(cnt--)tmp.push_back(i);
    }
    
    do{
        int idx=0;
        int sum=arr[0];
        for(auto c=tmp.begin(); idx<N; idx++,c++){
            if(c==tmp.end())continue;
            if(*c==0)sum+=arr[idx+1];
            else if(*c==1)sum-=arr[idx+1];
            else if(*c==2)sum*=arr[idx+1];
            else sum/=arr[idx+1];
            // sum이 10억이하, -10억이상으로 제한되어있음
            if(sum>=MAX)sum=MAX;
            if(sum<=MIN)sum=MIN;
        }
        ans_max=max(sum,ans_max);
        ans_min=min(sum,ans_min);
    }while(next_permutation(tmp.begin(),tmp.end()));
    cout << ans_max << '\n' << ans_min ;
}