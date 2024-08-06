// 1H30M

// 문제는 쉬우나 조건이 꽤 까다로워 예외처리가 많이들어감
// 조금 더 간결한 코드 구현하기

// 완전 스파게티코드 ㄷㄷ
// 그냥 풀이 생각나는대로 풀었더니 계산 지저분, 고치기도 어려움
// 함수화해서 푸는 습관 들이자

#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int N,L;
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for(int i=0; i<N ;i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
        }
    }

    // 가로체크
    for(int i=0; i<N ;i++){
        int f_b=board[i][0];
        int cnt=1;
        bool chk=true;
        bool isslope[102]={0,};
        for(int j=1; j<N; j++){
            // 진행중 높이가 달라지면
            if(f_b!=board[i][j]){
                // 높이차이가 1차이면서 내려갈때
                if(f_b-board[i][j]==1 && !isslope[j]){
                    cnt=1;
                    // 경사로길이 L만큼의 공간이 확보되는지 확인
                    for(int k=j+1; k<N; k++)if(board[i][j]==board[i][k])cnt++;
                    // 확보되면 경사로 설치
                    if(cnt>=L) {
                        f_b=board[i][j];
                        cnt=1;
                        for(int s=j; s<j+L; s++)isslope[s]=true;
                    }
                    // 통과불가능
                    else chk=false;
                }
                // 높이차이가 1차이면서 올라갈때
                else if(f_b-board[i][j]==-1){
                    // 경사로길이 L만큼의 공간 확보되는지 확인
                    for(int k=j-1; k>j-1-L; k--)if(isslope[k])chk=false;
                    // 설치
                    if(cnt>=L){
                        f_b=board[i][j];
                        cnt=1;
                        for(int s=j-1; s>j-1-L; s--)isslope[s]=true;
                    }
                    // 안되면 통과불가능
                    else chk=false;
                }
                // 안되면 통과불가능
                else chk=false;
            }
            else cnt++;
        }
        // 최종 길통과되면 ans 증가
        if(chk==true)ans++;
    }

    // 세로체크 
    // 가로와 동일한 로직
    for(int i=0; i<N ;i++){
        int f_b=board[0][i];
        int cnt=1;
        bool chk=true;
        bool isslope[102]={0,};
        for(int j=1; j<N; j++){
            if(f_b!=board[j][i]){
                if(f_b-board[j][i]==-1 && !isslope[j-1]){
                    for(int k=j-1; k>j-1-L; k--)if(isslope[k])chk=false;
                    if(cnt<L)chk=false;
                    else{
                        f_b=board[j][i];
                        cnt=1;
                        for(int s=j-1; s>j-L; s--)isslope[s]=true;
                    }
                }
                else if(f_b-board[j][i]==1 && !isslope[j]){
                    cnt=1;
                    for(int k=j+1; k<N; k++)if(board[j][i]==board[k][i])cnt++;
                    if(cnt>=L){
                        f_b=board[j][i];
                        cnt=1;
                        for(int s=j; s<j+L; s++)isslope[s]=true;
                    }
                    else chk=false;
                }
                else chk=false;
            }
            else cnt++;
        }
        if(chk==true)ans++;
    }
    cout << ans;
}