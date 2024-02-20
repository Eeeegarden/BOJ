// 푸는중
// 생각보다 어려운듯


#include <bits/stdc++.h>
using namespace std;

int N;
int m[22][22];
int m2[22][22];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int ans=0;
int cnt=0;


void mv(int m2[22][22],int cnt){
    if(cnt>=5){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(ans<=m2[i][j])ans=m2[i][j];
            }
        }
        return;
    }
    // 백트래킹 완료되면 합쳐져있는 블록은 해체, cnt감소
    // 블록이 존재하는 위치가 아니면 한칸씩 내림
    for(int dir=0; dir<4; dir++){
        // 상
        if(dir==0){
            int isused[22][22]={0,};
            for(int y=0; y<N; y++){
                for(int x=0; x<N; x++){
                    int nx=x;
                    if(x<0 || y<0 || x>=N || y>=N) continue;
                    // 빈칸이면 한칸씩 위로 밈
                    if(m2[x][y]==0){
                        int s=0;
                        while(s<N){
                            m2[nx][y]=m2[nx+1][y];
                            s++;
                        }
                    }                    
                    // 합쳐지지 않은 같은수가 연속적으로 존재하면 합체
                    if(m2[x+1][y]==m2[x][y] && !isused[x][y] && x>0 && m2[x][y]!=0){
                        m2[x][y]*=2;
                        m2[x+1][y]=0;
                        isused[x][y]=1;
                    }
                }
            }
        }
        cout << "----------------------" << '\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << m2[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << cnt << '\n';
        cnt++;
        mv(m2,cnt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> m[i][j];
        }
    }
    mv(m,0);
    cout << ans;
}