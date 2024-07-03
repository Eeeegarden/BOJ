// 4H 30M 걸림 

// 코드 로직
/*
입력 -> 체크 -> O -> 삽입
             -> X -> 평이 -> O 
                          -> X -> 90회전 -> O
                                         -> X -> 180,270 회전 -> O
                                                              -> X -> 스티커 건너뜀

시간복잡도 걸릴줄 알았는데 안걸림 -> 최악 48,000,000 
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m[50][50]={0,}; // 노트북
int N,M,K;
int flag=0;
int ans=0;

// 평행이동된 스티커와 노트북 비교 함수
// 스티커 모양대로 노트북에 자리있으면 노트북갱신,flag=1 저장
void check_s(int x,int y,int hei,int len,int s[50][50],int s_num){
    int m2[50][50];
    int cnt=0;
    copy(m[0],m[0]+2500,m2[0]);
    for(int i=0; i<hei; i++){
        for(int j=0; j<len; j++){
            if(m[x+i][y+j]==1 && s[i][j]==1) return;
            if(m[x+i][y+j]==0 && s[i][j]==0) continue;
            if(m[x+i][y+j]==0 && s[i][j]==1){
                cnt++;
                m2[x+i][y+j]=1;
            }
            if(cnt==s_num){
                copy(m2[0],m2[0]+2500,m[0]);
                flag=1;
                return;
            }
        }
    }
    return;
}

// 스티커 평행이동 시키면서 노트북 탐색
void quest(int h,int l,int s[50][50],int s_num){
    for(int j=0; j<N; j++){
        for(int q=0; q<M; q++){
            if(j+h>N || q+l>M) continue;
            check_s(j,q,h,l,s,s_num);
            if(flag==1)return;
        }
    }
    return;
}

// 시계방향 90도 회전함수
void rotate_s(int h,int l,int s[50][50],int s_num){
    int tmp_arr[50][50]={0,};
    for(int i=0; i<l; i++){
        for(int j=0; j<h; j++){
            tmp_arr[i][j]=s[h-1-j][i];
        }
    }
    copy(tmp_arr[0],tmp_arr[0]+2500,s[0]);
    return;
}

// 삽입
void insert_s(int h,int l,int s[50][50],int s_num){
    flag=0; // 삽입됐는지 체크변수
    quest(h,l,s,s_num); // 노트북 탐색함수

    // 노트북 탐색했는데 안들어갈때 90도 회전시키고 다시탐색
    if(flag==0){
        for(int num=0; num<4 && flag==0; num++){
            int tmp;
            rotate_s(h,l,s,s_num);
            tmp=h;
            h=l;
            l=tmp;
            quest(h,l,s,s_num);
        }
        return;
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    for(int i=0; i<K; i++){
        int hei,len;
        int s_num=0; // 스티커 크기
        int s[50][50]={0,}; // 스티커 종이
        cin >> hei >> len;
        for(int j=0; j<hei; j++){
            for(int q=0; q<len; q++){
                cin >> s[j][q];
                if(s[j][q]==1)s_num++;
            }
        }
        insert_s(hei,len,s,s_num);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(m[i][j]==1)ans++;
        }
    }
    cout << ans;
}