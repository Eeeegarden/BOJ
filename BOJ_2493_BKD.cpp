//Autored by : twinkite
#include <bits/stdc++.h>
using namespace std;

int N;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> tower;
    cin >> N;

    tower.push({100000005,0});
    for(int i=1; i<=N; i++){
        int h;
        cin >> h;
        while(tower.top().first<h){
            tower.pop();
        }
        cout << tower.top().second << " " ;
        tower.push({h,i});
    }

}