#include <bits/stdc++.h>
using namespace std;

string s;
string t;
bool issame=true;

// 최소 공배수 찾기
int fx(int a, int b){
    int num1 = a;
    int num2 = b;
    while(num1!=num2){
        if(num1>num2)num2+=b;
        else num1+=a;
    }
    return num1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    // 긴거를 s로 
    if(max(s.length(), t.length())==t.length()) {
        swap(s,t);
    }

    //최소공배수
    int gcd_num = fx(s.length(), t.length());

    for(int i=0; i<gcd_num; i++){
        if(s[i%s.length()] != t[i%t.length()]) issame = false;
    }

    if(issame) cout << "1";
    else cout << "0";
}