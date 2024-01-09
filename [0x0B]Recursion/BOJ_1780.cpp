// 범위 설정잘못해서 애쓴문제..
// 재귀문제 접근시 1. 함수의 정의 <<- 함수형태와 넘겨주는 인자 잘 확인하기
//                 2. base condition
//                 3. 재귀 식

// line43 : 범위를 i<n 으로해서 틀림 i<n+row 로 해야함
// n이 작아져도 9칸 모두검사해야하기때문에
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2200][2200];
int cnt[3]={0,};

bool checkbox(int row,int col,int box){
    for(int i=row; i<box+row; i++){
        for(int j=col; j<box+col; j++){
            if(arr[row][col]!=arr[i][j])return false;
        }
    }
    return true;
}

void count(int row,int col,int n){
    int box = n/3;
    if(box<=1){
        if(checkbox(row,col,3)==false){
            for(int i=row; i<n+row; i++){
                for(int j=col; j<n+col; j++){
                    if(arr[i][j]==-1)cnt[0]++;
                    else if(arr[i][j]==0)cnt[1]++;
                    else cnt[2]++;
                }
            }
        }
        else{
            if(arr[row][col]==-1)cnt[0]++;
            else if(arr[row][col]==0)cnt[1]++;
            else cnt[2]++;
        }
    }
    else {
        if(checkbox(row,col,n)==false){
            for(int i=row; i<n+row; i=i+box){
                for(int j=col; j<n+col; j=j+box){
                    if(checkbox(i,j,box)==false) count(i,j,box);
                    else {
                        if(arr[i][j]==-1) cnt[0]++;
                        else if(arr[i][j]==0) cnt[1]++;
                        else cnt[2]++;
                    }
                }
            }
        }
        else cnt[arr[row][col]+1]++;
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

    count(0,0,n);

    for(auto c : cnt){
        cout << c << '\n';
    }
}
