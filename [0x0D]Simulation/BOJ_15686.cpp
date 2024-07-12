// 푸는중

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int board[52][52];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
int dis[52]={0,};
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j]==1)house.push_back({i,j});
            else if(board[i][j]==2)chicken.push_back({i,j});
        }
    }
    for(int i=0; i<house.size(); i++){
        for(int j=0; j<chicken.size(); j++){
            int dis_X = (house[i].X - chicken[j].X>0) ? house[i].X - chicken[j].X : -(house[i].X - chicken[j].X);
            int dis_Y = (house[i].Y - chicken[j].Y>0) ? house[i].Y - chicken[j].Y : -(house[i].Y - chicken[j].Y);
            // cout << house[i].X << house[i].Y << '/' << chicken[j].X << chicken[j].Y  << ' ' << dis_X << dis_Y << '\n';
            if(dis[i]==0)dis[i]=dis_X+dis_Y;
            else dis[i]=min(dis_X+dis_Y,dis[i]);
        }
    }

    for(int i=0; i<house.size(); i++){
        ans += dis[i];
        // cout << dis[i] << ' ';
    }
    

    
    cout << ans;


}