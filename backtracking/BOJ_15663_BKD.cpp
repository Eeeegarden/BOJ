// Authored by : connieya , BaaaaaaaaaaarkingDog

// 답지참조 : func함수에서 k!=m 이면 tmp 초기화 후 for문에서 arr[k]값 들고감
// func(k+1) 에서 k!=m 이면 다시 초기화 --> 쭉 진행되다가
// k==m이면 arr배열 출력 후 arr배열의 마지막 tmp 값 보전됨 (함수 return)
// 마지막 tmp 값과 num[i] 값을 비교하여 중복 집합 예외처리 가능 

#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
int num[10];
bool isused[11];

void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] <<' ' ;
        }
        cout << '\n';
        return;
    }
    int tmp=20000;
    for(int i=0; i<n; i++){
        if(!isused[i]){
            if(tmp==num[i])continue;
            isused[i]=1;
            arr[k]=num[i];
            tmp=arr[k];
            func(k+1);
            isused[i]=0;
        }
    }
}
            
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    sort(num,num+n);

    func(0);
}
