// 조합 이용해서 치킨집 경우의수 구해서 거리구하기
// 런타임에러 -> 배열 범위 잘 생각하기 (보드 50*50이면 dis는 2500이상으로 설정)

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int board[52][52];
vector<pair<int,int>> house;
vector<pair<int,int>> w_chicken;
vector<pair<int,int>> chicken;
int ans=INT_MAX;


void combination(int start, vector<pair<int,int>> chicken){
    if(chicken.size() == M){
        int dis[3000]={0,};
        int w_dis=0;
        for(int i=0; i<house.size(); i++){
            for(int j=0; j<chicken.size(); j++){
                int dis_X = (house[i].X - chicken[j].X>0) ? house[i].X - chicken[j].X : -(house[i].X - chicken[j].X);
                int dis_Y = (house[i].Y - chicken[j].Y>0) ? house[i].Y - chicken[j].Y : -(house[i].Y - chicken[j].Y);
                if(dis[i]==0)dis[i]=dis_X+dis_Y;
                else dis[i]=min(dis_X+dis_Y,dis[i]);
            }
        }
        for(int k=0; k<house.size(); k++){
            w_dis+=dis[k];
        }
        ans=min(w_dis,ans);
        return;
    }
    for(int q=start+1; q<w_chicken.size(); q++){
        chicken.push_back({w_chicken[q].X,w_chicken[q].Y});
        combination(q, chicken);
        chicken.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j]==1)house.push_back({i,j});
            else if(board[i][j]==2)w_chicken.push_back({i,j});
        }
    }

    combination(-1, chicken);
    cout << ans;
}