// 배열 내 모두 다른 자연수 이기 때문에 np사용가능

#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[10];
int temp[10]={0,};
int pre[10]={0,};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr,arr+N);
    for(int i=1; i<=N-M; i++) temp[N-i] = 1;
    
    do{
        for(int i=0; i<N; i++){
            if(temp[i] == 0) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    }while(next_permutation(temp, temp+N));

    

}