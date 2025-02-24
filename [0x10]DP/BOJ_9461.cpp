/*
테이블
d[i]

점화식
1부터 삼각형 한 변씩 사용하는 형태
d[i] = d[i-1] + 안쓴 삼각형
*/

#include<bits/stdc++.h>
using namespace std;

int T;
long long N[102];
long long d[102];
int isused[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    d[0]=1;
    d[1]=1;
    d[2]=1;
    d[3]=2;
    d[4]=2;
    d[5]=3;
    isused[1]= true;

    // 6부터 d[i] = i-1 + 안쓴거 중 제일 작은거
    for(int i=6; i<102; i++){
        for(int j=0; j<i; j++){
            if(!isused[j]) {
                d[i] = d[i-1] + d[j];
                isused[j] = true;
                break;
            }
        }
    }

    for(int i=0; i<T; i++){
        cin >> N[i];
        cout << d[N[i]-1] << '\n';
    }
}