// 38min 
// 단순구현
// max,min 사용시 중괄호로 여러개 값 비교가능
// stack.top(),size() 이용한 풀이 가능? 백준 레이저 비슷한문제?

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1002];

int check_four(int n, int* arr){
    //1
    if(n>=2 && arr[n-2]>arr[n])return 0;
    //2
    if(n>=1 && arr[n-1]>arr[n])return 0;
    //3
    if(arr[n+1]>arr[n])return 0;
    //4
    if(arr[n+2]>arr[n])return 0;
    
    if(n>=2) return arr[n] - max({arr[n-2],arr[n-1],arr[n+1],arr[n+2]});
    else if(n>=1) return arr[n] - max({arr[n-1],arr[n+1],arr[n+2]});
    else return arr[n] - max(arr[n+1],arr[n+2]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<10; i++){
        int ans=0;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int j=0; j<n; j++){
            ans += check_four(j,arr);
        }
        cout << "#" << i+1 << ' ' << ans << '\n';
    }
}

