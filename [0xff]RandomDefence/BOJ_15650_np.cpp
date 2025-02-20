// next_permutation 풀이
#include <bits/stdc++.h>
using namespace std;

int arr[10]={0,};
int temp[10]={0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;

    cin >> N >> M;

    for(int i=0; i<N; i++) arr[i] = i+1;
    for(int i=N-M; i>0; i--) temp[N-i] = 1; // 선택 개수, 오름차순으로

    do{
        for(int i=0; i<N; i++){
            if(temp[i]==0) cout << arr[i] << ' ';
        }
        cout << '\n';
    }while(next_permutation(temp, temp+N));

}