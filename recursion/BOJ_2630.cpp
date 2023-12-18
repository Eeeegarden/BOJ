// BOJ_1780 하고 비슷 똑같이 품
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2000][2000];
int cnt[2]={0,};

bool checkbox(int row, int col,int box){
    for(int i=row; i<box+row; i++){
        for(int j=col; j<box+col; j++){
            if(arr[row][col]!=arr[i][j]) return false;
        }
    }
    return true;
}

void countpaper(int row,int col,int n){
    int box = n/2;
    if(checkbox(row,col,n)==true){
        cnt[arr[row][col]]++;
        return;
    }
    for(int i=row; i<n+row; i=i+box){
        for(int j=col; j<n+col; j=j+box){
            if(checkbox(i,j,box)==true) cnt[arr[i][j]]++;
            else countpaper(i,j,box);
        }
    }
}
            

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    countpaper(0,0,n);

    cout << cnt[0] << '\n' << cnt[1];

}
