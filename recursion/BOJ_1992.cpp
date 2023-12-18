#include <bits/stdc++.h>
using namespace std;

string arr[70];
int n;

bool checkbox(int row,int col,int n){
    for(int i=row; i<row+n; i++){
        for(int j=col; j<col+n; j++){
            if(arr[row][col]!=arr[i][j])return false;
        }
    }
    return true;
}

void quadtree(int row,int col,int n){
    int box = n/2;
    if(checkbox(row,col,n)==true){
        cout << arr[row][col];
        return;
    }
    cout << '(';
    for(int i=row; i<row+n; i=i+box){
        for(int j=col; j<col+n; j=j+box){
            if(checkbox(i,j,box)==true){
                cout << arr[i][j];
            }
            else quadtree(i,j,box);
        }
    }
    cout << ')';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    quadtree(0,0,n);
}

