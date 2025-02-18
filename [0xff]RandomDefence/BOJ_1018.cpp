#include <bits/stdc++.h>
using namespace std;

int N,M;
string s[52];
int ans = INT_MAX;

int cntfx(int x, int y){
    string W = "WBWBWBWB";
    string B = "BWBWBWBW";
    int cntW=0;
    int cntB=0;
    // W인 경우
    for(int i=x; i<x+8; i++){
        for(int j=y; j<y+8; j++){
            if(i%2 == 0){
                if(W[j-y] != s[i][j])cntW++;
            }
            else {
                if(B[j-y] != s[i][j])cntW++;
            }
        }
    }
    // B인 경우
    for(int i=x; i<x+8; i++){
        for(int j=y; j<y+8; j++){
            if(i%2 == 0){
                if(B[j-y] != s[i][j])cntB++;
            }
            else {
                if(W[j-y] != s[i][j])cntB++;
            }
        }
    }
    return min(cntW,cntB);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> s[i];
    }

    for(int i=0; i+8<=N; i++){
        for(int j=0; j+8<=M; j++){
            ans = min(ans, cntfx(i,j));
        }
    }

    cout << ans;
}
