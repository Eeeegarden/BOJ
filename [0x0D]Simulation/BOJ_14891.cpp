// 3H 20M
// 처음 상태에서 모든 톱니바퀴 체크 후 한번에 돌리도록 풀었으면 조금 더 쉬웠을듯


// 나는 입력받은 톱니바퀴 기준으로 오른쪽 다돌리고, 왼쪽 다돌리고, 선택된 톱니바퀴 돌리도록
// 이렇게 푸니까 생각할게 많았던 문제.. (1번톱니바퀴 돌릴때 2,3,4가 다돌아가는 경우)
#include <bits/stdc++.h>
using namespace std;

string gear[4];
int K;
int t_gearnum;
int t_dir;
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<4; i++){
        cin >> gear[i];
    }

    cin >> K;

    for(int i=0; i<K; i++){
        cin >> t_gearnum >> t_dir;
        // gearnum, dir = 계산을 위한 변수
        int gearnum=t_gearnum-1;
        int dir=t_dir;
        char b_gear;
        bool iswork=true;
        
        // 오른쪽 톱니바퀴 돌아가는경우
        if(gearnum<3)b_gear=gear[gearnum][2];
        while(iswork){
            iswork=false;
            if(gearnum<3 && (b_gear!=gear[gearnum+1][6])){
                iswork=true;
                b_gear=gear[gearnum+1][2];
                if(dir==-1){
                    char tmp=gear[gearnum+1][7];
                    for(int i=7; i>=1; i--){
                        gear[gearnum+1][i]=gear[gearnum+1][i-1];
                    }
                    gear[gearnum+1][0]=tmp;
                }
                else{
                    char tmp=gear[gearnum+1][0];
                    for(int i=0; i<7; i++){
                        gear[gearnum+1][i]=gear[gearnum+1][i+1];
                    }
                    gear[gearnum+1][7]=tmp;
                }
            gearnum++;
            dir*=-1;
            }
        }
        // 왼쪽 톱니바퀴 돌아가는경우
        iswork=true;
        gearnum=t_gearnum-1;
        dir=t_dir;
        if(gearnum>0)b_gear=gear[gearnum][6];
        while(iswork){
            iswork=false;
            if(gearnum>0 && (b_gear!=gear[gearnum-1][2])){
                iswork=true;
                b_gear=gear[gearnum-1][6];
                if(dir==-1){
                    char tmp=gear[gearnum-1][7];
                    for(int i=7; i>=1; i--){
                        gear[gearnum-1][i]=gear[gearnum-1][i-1];
                    }
                    gear[gearnum-1][0]=tmp;
                }
                else{
                    char tmp=gear[gearnum-1][0];
                    for(int i=0; i<7; i++){
                        gear[gearnum-1][i]=gear[gearnum-1][i+1];
                    }
                    gear[gearnum-1][7]=tmp;
                }
            gearnum--;
            dir*=-1;
            }
        }
        
        // 선택된 톱니바퀴 돌림
        dir=t_dir;
        gearnum=t_gearnum-1;
        if(dir==1){
            char tmp=gear[gearnum][7];
            for(int i=7; i>=1; i--){
                gear[gearnum][i]=gear[gearnum][i-1];
            }
            gear[gearnum][0]=tmp;
        }
        else{
            char tmp=gear[gearnum][0];
            for(int i=0; i<7; i++){
                gear[gearnum][i]=gear[gearnum][i+1];
            }
            gear[gearnum][7]=tmp;
        }
    }

    for(int i=0; i<4; i++){
        if(gear[i][0]=='1')ans+=1<<i;
    }
    cout << ans;
}