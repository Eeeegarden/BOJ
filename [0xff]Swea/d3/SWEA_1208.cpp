#include <bits/stdc++.h>
using namespace std;

int box_mxidx(int* box){
    int mx = 0;
    int mx_idx=0;
    for(int i=0; i<100; i++){
        if(box[i]>=mx){
            mx = box[i];
            mx_idx = i;
        }
    }
    return mx_idx;
}

int box_mnidx(int* box){
    int mn = 100;
    int mn_idx=0;
    for(int i=0; i<100; i++){
        if(box[i]<=mn){
            mn = box[i];
            mn_idx = i;
        }
    }
    return mn_idx;
}

void fxdump(int* box, int mxidx, int mnidx){
    box[mxidx] -= 1;
    box[mnidx] += 1;
}

int cal_hd(int* box){
    int mx_idx = box_mxidx(box);
    int mn_idx = box_mnidx(box);
    return box[mx_idx] - box[mn_idx];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int tc=1; tc<=10; tc++){
        int dump;
        int box[102];

        cin >> dump;
        for(int i=0; i<100; i++){
            cin >> box[i];
        }
        for(int i=0; i<dump; i++){
            int mx_idx = box_mxidx(box);
            int mn_idx = box_mnidx(box);
            fxdump(box, mx_idx, mn_idx);
        }
        cout << '#' << tc << ' ' << cal_hd(box) << '\n';
    }

}