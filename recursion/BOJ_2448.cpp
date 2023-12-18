// 푸는중
#include <bits/stdc++.h>
using namespace std;

char arr[5000][5000];

void startree(int row, int col, int n){
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        fill(arr[i],arr[i]+n,'0');
    }

    startree(0,0,n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j];
        }
        cout <<'\n';
    }
}

