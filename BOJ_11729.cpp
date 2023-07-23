#include <bits/stdc++.h>
using namespace std;
void func(int a,int b,int n);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n)- 1 << '\n'; // 1을 n비트만큼밀어라 (제곱계산시 편리)
    func(1,3,n);

}

void func(int a, int b, int n) // 출발기둥,도착기둥,원판개수
{
    if(n==1) {
        cout << a << ' ' << b << '\n' ;
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n' ;
    func(6-a-b,b,n-1);
}