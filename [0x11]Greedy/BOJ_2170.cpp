#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
vector<pair<int,int>> coordinate;
vector<pair<int,int>> ans;
int res=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        coordinate.push_back({x,y});
    }
    sort(coordinate.begin(), coordinate.end());
 
    int min_x = coordinate[0].X;
    int max_y = coordinate[0].Y;
    
    for(int i=1; i<N; i++){
        // 덧 대서 그리는 경우
        if(coordinate[i].X <= max_y) max_y = (coordinate[i].Y >= max_y) ? coordinate[i].Y : max_y;
        // 새로운 선 그어지는 경우 그리던 선 ans에 넣음
        if(coordinate[i].X > max_y) {
            ans.push_back({min_x, max_y});
            min_x = coordinate[i].X;
            max_y = coordinate[i].Y;
        }
        // 마지막에 그리던 선 ans에 넣음
        if(i==N-1 && (ans.empty() || min_x != ans.back().X)){
            ans.push_back({min_x,max_y});
        }
    }
    if(ans.empty()) res += abs(max_y - min_x);
    for(int i=0; i<ans.size(); i++){
        res += abs(ans[i].Y - ans[i].X);
    }
    cout << res;
}