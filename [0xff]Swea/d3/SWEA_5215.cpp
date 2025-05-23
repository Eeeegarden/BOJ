// 최악의 경우 20! 백트래킹 불가 14!이 800억넘음
// 
#include <bits/stdc++.h>
using namespace std;

int T;
int N,L;
int s[1002];
int c[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int tc=1; tc<=T; tc++){
        cin >> N >> L;
        for(int i=0; i<N; i++){
            cin >> s[i] >> c[i];
        }
        
        

        
        cout << '#' << tc << ' ' <<  '\n';
    }
}