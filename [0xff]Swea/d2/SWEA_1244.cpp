#include <bits/stdc++.h>
using namespace std;

int T;
int num;
int ch_cnt;
int digit;
int mx_num=0;
bool chk_sort;
int a[7]={0,};

// 자릿수 계산 함수
int fx_digit(int n){
    int d=0;
    while(n>0){
        n/=10;
        d++;
    }
    return d;
}

// 배열 -> 정수 변환 함수
int cal_a(int* a){
    int num=0;
    int d=1;
    for(int i=digit; i>0; i--){
        num += d*a[i];
        d*=10;
    }
    return num;
}

// 내림차순 인지 확인하는 함수
bool issort(int* b){
    for(int w=1; w<digit; w++){
        if(b[w]<b[w+1])return false;
    }
    return true;
}


void bt(int k){
    // 계산 줄이기 위해 정렬된 상태, 교환횟수에 따라 미리 판단하도록
    if(issort(a) && (abs(k-ch_cnt)%2==0)){
        mx_num = cal_a(a);
        chk_sort=true;
        return;
    }
    if(issort(a) && ((abs(k-ch_cnt))%2==1)){
        // 무조건 1의자리랑 10의자리 바꾸는게 아닌 중복된 숫자가 있는지 확인
        for(int e=1; e<digit; e++){
            if(a[e]==a[e+1]){
                mx_num=cal_a(a);
                chk_sort=true;
                return;
            }
        }
        // 중복 숫자가 없다면 1,10자리 바꿨을때 가장 큰 수
        swap(a[digit-1],a[digit]);
        mx_num=cal_a(a);
        chk_sort=true;
        return;
    }
    if(k==ch_cnt){
        if(cal_a(a)>mx_num)mx_num=cal_a(a);
        return;
    }
    for(int i=1; i<digit; i++){
        for(int j=i+1; j<=digit; j++){
            if(chk_sort==true)return;
            swap(a[i],a[j]);
            bt(k+1);
            swap(a[i],a[j]);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int testcase=1; testcase<=T; testcase++){
        cin >> num >> ch_cnt;
        digit = fx_digit(num);
        for(int i=digit; i>0; i--){
            a[i] = num%10;
            num/=10;
        }
        chk_sort=false;
        bt(0);
        cout << '#' << testcase << ' ' << mx_num << '\n';
        
    }
}