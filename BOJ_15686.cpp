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
            int dis_X = (house[i].X - chicken[i].X>0) ? house[i].X - chicken[i].X : -(house[i].X - chicken[i].X);
            int dis_Y = (house[i].Y - chicken[i].Y>0) ? house[i].Y - chicken[i].Y : -(house[i].Y - chicken[i].Y);
            cout << i << j  << ' ' << dis_X << dis_Y << '\n';
            if(dis[i]==0)dis[i]=dis_X+dis_Y;
            else dis[i]=min(dis_X+dis_Y,dis[i]);
        }
    }

    for(int i=0; i<house.size(); i++){
        ans += dis[i];
        cout << dis[i] << ' ';
    }
    

    
    cout << '\n' << ans;


}