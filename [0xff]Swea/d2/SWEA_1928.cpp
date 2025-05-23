/*
1. 표1을 보고 입력받은 문자들을 각각 대응하는 숫자로 변경한다.
2. 각 숫자들을 6자리 이진수로 표현하고, 이 이진수들을 한 줄로 쭉 이어 붙인다.
3. 한 줄로 쭉 이어붙인 이진수들을 8자리씩 끊어서 십진수로 바꾼다.
4. 각각의 십진수를 아스키 코드로 변환한다.
*/
#include <bits/stdc++.h>
using namespace std;

string base64_encoder = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
string s;
int T;
int en1[1000002]={0,};
int en2[1000002];

void en1_fx(int a, int k){
    int b = 32;
    int c=0;
    while(a>0 || c<6){
        if(a>=b){
            a-=b;
            en1[c+k]=1;
            b/=2;
            c++;
        }
        else {
            en1[c+k]=0;
            c++;
            b/=2;
        }
    }
}

int en2_fx(int k){
    // 11111111
    int b = 128;
    int c=0;
    int sum=0;
    while(c<8){
        if(en1[c+k]==1){
            sum+=b;
            b/=2;
            c++;
        }
        else {
            b/=2;
            c++;
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int testcase=1; testcase<=T; testcase++){
        cin >> s;
        for(int i=0; i<s.length(); i++){
            // en1 2진수로 초기화됨
            for(int j=0; j<64; j++){
                if(s[i] == base64_encoder[j]){
                    en1_fx(j,i*6);
                }
            }
        }
        // 8자리씩 끊어서 변환
        cout << '#' << testcase << ' ';
        for(int j=0; j<s.length()*6; j+=8){
            cout << (char)en2_fx(j);
        }
        cout << '\n';
    }
}