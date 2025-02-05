#include <bits/stdc++.h>
using namespace std;

int A[2000002]={0,};
int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        A[num+1000000]++;
    }
    for(int i=0; i<2000002; i++){
        if(A[i]!=0){
            for(int j=0; j<A[i]; j++){
                cout << i-1000000 << '\n';
            }
        }
    }
}