// 푸는중 1H45M ~ing


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

    // 12시부터
    // 1번째 기어 = index:2 톱니
    // 2번째 기어 = 6,2 톱니
    // 3 ..
    // 4번째 기어 = 6 톱니
    // N극 0, S극 1
    // 시계방향 1, 반시계방향 -1

    for(int i=0; i<K; i++){
        cin >> t_gearnum >> t_dir;
        int gearnum=t_gearnum-1;
        int dir = t_dir;
        bool iswork=true;
        // 지금은 1번만 하고 멈춤 끝까지 도는경우 체크해야함
        // 1번돌았을때 2,3,4 다도는 경우
        // 오른쪽 톱니바퀴
        // 왼쪽톱니바퀴가 시계로돌면 오른쪽톱니바퀴는 반시계로돈다...
        // 이거 체크안했네;
        // 다 체크완료인데 1%에서 틀림
        while(iswork){
            iswork=false;
            if(gearnum<3 && (gear[gearnum][2]!=gear[gearnum+1][6])){
                iswork=true;
                if(dir==-1){
                    int tmp=gear[gearnum+1][7];
                    for(int i=7; i>=1; i--){
                        gear[gearnum+1][i]=gear[gearnum+1][i-1];
                    }
                    gear[gearnum+1][0]=tmp;
                }
                else{
                    int tmp=gear[gearnum+1][0];
                    for(int i=0; i<7; i++){
                        gear[gearnum+1][i]=gear[gearnum+1][i+1];
                    }
                    gear[gearnum+1][7]=tmp;
                }
            gearnum++;
            dir*=-1;
            }
        }
        // 왼쪽 톱니바퀴
        iswork=true;
        gearnum=t_gearnum-1;
        dir=t_dir;
        while(iswork){
            iswork=false;
            if(gearnum>0 && (gear[gearnum][6]!=gear[gearnum-1][2])){
                iswork=true;
                if(dir==-1){
                    int tmp=gear[gearnum-1][7];
                    for(int i=7; i>=1; i--){
                        gear[gearnum-1][i]=gear[gearnum-1][i-1];
                    }
                    gear[gearnum-1][0]=tmp;
                }
                else{
                    int tmp=gear[gearnum-1][0];
                    for(int i=0; i<7; i++){
                        gear[gearnum-1][i]=gear[gearnum-1][i+1];
                    }
                    gear[gearnum-1][7]=tmp;
                }
            gearnum--;
            dir*=-1;
            }
        }
        dir=t_dir;
        // 돌릴 톱니바퀴
        if(dir==1){
            int tmp=gear[gearnum][7];
            for(int i=7; i>=1; i--){
                gear[gearnum][i]=gear[gearnum][i-1];
            }
            gear[gearnum][0]=tmp;
        }
        else{
            int tmp=gear[gearnum][0];
            for(int i=0; i<7; i++){
                gear[gearnum][i]=gear[gearnum][i+1];
            }
            gear[gearnum][7]=tmp;
        }
        // cout << "-------------------" << '\n';
        // for(int i=0; i<4; i++){
        //     cout << gear[i] << '\n';
        // }
    }

    for(int i=0; i<4; i++){
        if(gear[i][0]=='1')ans+=1<<i;
    }
    cout << ans;
}