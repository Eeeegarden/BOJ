#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int s_num;
    int sum=0;
    stack<int> S;

    cin >> num;
    for(int i=0; i<num; i++){
        cin >> s_num;
        if(s_num != 0){
            S.push(s_num);
        }
        else if(s_num == 0){
            S.pop();
        }
    }

    while(!S.empty()){
        sum+=S.top();
        S.pop();
    }
    cout << sum;
}
