#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    string ans;
    int arr[100005]={0};

    int num;
    int count = 0;
    cin >> num;

    for(int i=0; i<num; i++){
        int n;
        cin >> n;
        arr[i]=n;
    }

    while(num--){
        static int i=0;
        while((count+1)<=arr[i]){
            S.push(count+1); 
            count++;
            ans += "+\n";
        }
        if(S.top()!=arr[i]){
            cout << "NO" << '\n';
            return 0;
        }
        S.pop();
        ans += "-\n";
        i++;
    }

    cout << ans;
}