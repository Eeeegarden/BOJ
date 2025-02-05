// 정렬 응용

#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[100002];

// 정렬된 배열로 갯수세기
long long cntfx(long long *arr, int N){
    int cnt=1;
    long long mxval=arr[0];
    int mxcnt=0;

    for(int i=1; i<N; i++){
        // 앞 인덱스 값과 다르면 카운트 및 값 갱신
        if(arr[i-1]!=arr[i]){
            if(cnt>mxcnt){
                mxcnt=cnt;
                mxval=arr[i-1];
            }
            cnt=1;
        }
        else cnt++;
        // 마지막 인덱스에서 카운트 해주기
        if(i==N-1){
            if(cnt>mxcnt){
                mxcnt=cnt;
                mxval=arr[i-1];
            }
        }
    }
    return mxval;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr,arr+N);
    cout << cntfx(arr,N);
}
