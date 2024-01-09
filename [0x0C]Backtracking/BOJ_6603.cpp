#include <bits/stdc++.h>
using namespace std;

int k;
int arr[20];
int num[15];
bool isused[15];

void func(int n){
    if(n==6){
        for(int i=0; i<6; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }   
    for(int i=0; i<k; i++){
        if(!isused[i]){
            // 다시 돌아갈일없으니까 
            // isused 안쓰고 증가시키는형태로 풀어도됨
            if(num[i]<arr[n-1])continue;
            isused[i]=1;
            arr[n]=num[i];
            func(n+1);
            isused[i]=0;
        }
    }
}
    


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> k;
        if(k==0)break;
        for(int i=0; i<k; i++){
            cin >> num[i];
        }
        func(0);
        cout << '\n';
    }
}

