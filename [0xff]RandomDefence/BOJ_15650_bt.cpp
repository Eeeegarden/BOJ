// 백트래킹 풀이
// 순서대로 진행하기 때문에 방문체크 isused 필요없음
#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[10];

void func(int k){
    if(k==M){
        for(int i=0; i<M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=N; i++){
        // 사전 순으로 증가하도록
        if(k!=0 && i<=arr[k-1])continue;
        arr[k] = i;
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    func(0);

}