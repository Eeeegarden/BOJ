#include <bits/stdc++.h>
using namespace std;

int N;
int arr[52];
vector<int> temp1;
vector<int> temp2;
vector<int> temp3;
int ans=0;

bool comp(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        if(arr[i] > 0) temp1.push_back(arr[i]);
        else if(arr[i] == 0) temp2.push_back(arr[i]);
        else temp3.push_back(arr[i]); 
    }
    sort(temp1.begin(), temp1.end(), comp);
    sort(temp2.begin(), temp2.end());
    sort(temp3.begin(), temp3.end());

    for(int i=0; i+1<temp1.size(); i+=2){
        if(temp1[i] * temp1[i+1] > temp1[i] + temp1[i+1]) ans += temp1[i] * temp1[i+1];
        else ans += temp1[i] + temp1[i+1];
    }
    if(temp1.size()%2 == 1) ans += temp1.back();
    if(temp3.size()%2 == 1 && temp2.empty()) ans += temp3.back();
    for(int i=0; i+1<temp3.size(); i+=2){
        ans += temp3[i] * temp3[i+1];
    }

    cout << ans;
}