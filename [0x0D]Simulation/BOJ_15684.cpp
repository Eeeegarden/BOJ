// 2H 30M

// 인덱스 범위, 사다리화 할 수 있는 조건 등등 제약조건 잘 확인하기

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M,H;
int board[12][3000];
int row[3000][3000]={0,};
int ans=-1;
vector<pair<int,int>> nr;
queue<pair<int,int>> Q;

int lg(int row2[3000][3000]){
    for(int i=1; i<=N; i++)Q.push({1,i});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int fY=cur.Y;
        while(cur.X<H+1){
            // 오른쪽검사
            if(cur.Y<N && row2[cur.X][cur.Y]==1){
                cur.Y++;
                cur.X++;
            }
            // 왼쪽검사
            else if(cur.Y>1 && row2[cur.X][cur.Y-1]==1){
                cur.Y--;
                cur.X++;
            }
            else cur.X++;
        }
        if(cur.Y!=fY)return false;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    
    for(int i=0; i<M; i++){
        int c1,c2;
        cin >> c1 >> c2;
        row[c1][c2]=1;;
    }

    // 가로선이 될 수 있는 점들을 nr벡터에 삽입 -> 차례로 하나씩 추가해서 사다리게임진행하기위해
    for(int i=1; i<=H; i++)
        for(int j=1; j<N; j++)
            if(row[i][j-1]==0 && row[i][j]==0 && row[i][j+1]==0)nr.push_back({i,j});

    // 그대로
    if(lg(row)==true)ans=0;
    // 가로 1개 추가
    if(ans==-1){
        for(int i=0; i<nr.size(); i++){
            row[nr[i].X][nr[i].Y]=1;
            if(lg(row)==true)ans=1;
            row[nr[i].X][nr[i].Y]=0;
        }
    }
    // 가로 2개 추가
    if(ans==-1){
        for(int i=0; i<nr.size(); i++){
            row[nr[i].X][nr[i].Y]=1;
            for(int j=i+1; j<nr.size(); j++){
                row[nr[j].X][nr[j].Y]=1;
                if(lg(row)==true)ans=2;
                row[nr[j].X][nr[j].Y]=0;
            }
            row[nr[i].X][nr[i].Y]=0;
        }
    }
    // 가로 3개 추가
    if(ans==-1){
        for(int i=0; i<nr.size(); i++){
            row[nr[i].X][nr[i].Y]=1;
            for(int j=i+1; j<nr.size(); j++){
                row[nr[j].X][nr[j].Y]=1;
                for(int k=j+1; k<nr.size(); k++){
                    row[nr[k].X][nr[k].Y]=1;
                    if(lg(row)==true)ans=3;
                    row[nr[k].X][nr[k].Y]=0;
                }
                row[nr[j].X][nr[j].Y]=0;
            }
            row[nr[i].X][nr[i].Y]=0;
        }
    }
    cout << ans;
}