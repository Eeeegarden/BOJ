#include <iostream>
using namespace std;

void plusset(int set[],int& set_cnt){
    for(int i=0; i<10; i++){
        set[i]++;
    }
    set_cnt++;
}

int main(){
    int N;
    int set_cnt=0;
    int set[10]={};

    cin >> N;

    plusset(set,set_cnt);

    while(N>0){
        if(N%10 != 6 && N%10 !=9){
            if(set[N%10] != 0)set[N%10]--;
            else{
                plusset(set,set_cnt);
                set[N%10]--;
            }
        }
        else{
            if(set[6] == 0 && set[9] == 0){
                plusset(set,set_cnt);
                set[N%10]--;
            }
            else if(set[6] == 0 &&
            set[9] != 0)set[9]--;
            else set[6] --;
        }
        N/=10;
    }

    cout << set_cnt;
}