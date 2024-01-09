// Authored by : BaaaaaaaaaaarkingDog
// 1.함수의 정의 2.base condition 3.재귀 식

// 재귀 어렵다.. 
// 함수식은 이해했지만 변의길이 half를 이용하는 방법을 몰랐다.
// 제곱이 들어가면 비트연산으로 쉽게 가능하다는걸 생각하기
#include <bits/stdc++.h>
using namespace std;

int func(int n,int r,int c){
    if(n==0)return 0;
    // 한변 길이의 절반 2^(n-1)
    int half = 1<<(n-1);
    //1번
    if(n>r && n>c)return func(n-1,r,c);
    //2번
    if(n>r && n<=c)return func(n-1,r,c-n)+half*half;
    //3번
    if(n<=r && n>c)return func(n-1,r-n,c)+half*half*2;
    //4번
    if(n<=r && n<=c)return func(n-1,r-n,c-n)+half*half*3;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r,c;

    cin >> n >> r >> c;
    cout << func(n,r,c);

}
