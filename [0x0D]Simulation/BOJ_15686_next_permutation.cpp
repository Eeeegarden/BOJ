// 순열,조합 문제라면 C++ 한정 사기인 next_permutation 쓰자
// 실수 방지 및 코드간략화 쫌 사기인듯 ㄷㄷ

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int board[52][52];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
int ans=INT_MAX;


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
    vector<int> brute(chicken.size(),1);
    fill(brute.begin(),brute.begin() + chicken.size() - M, 0);
    do{
        int dis=0;
        for(auto h : house){
            int tmp=INT_MAX;
            for(int i=0; i<chicken.size(); i++){
                if(brute[i]==0)continue;
                tmp=min(tmp,abs(chicken[i].X-h.X)+abs(chicken[i].Y-h.Y));
            }
            dis+=tmp;
        }
        ans=min(ans,dis);
    }while(next_permutation(brute.begin(),brute.end()));
    cout << ans;
}