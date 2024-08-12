// 답지풀이
// 나중에 답지안보고 다시풀어보기

// line26:30 풀이방법 어케 생각하지 ㄷ

#include <bits/stdc++.h>
using namespace std;

int board[102][102];
queue<tuple<int,int,int,int>> Q;
int N,x,y,d,g;
int cnt=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        cin >> x >> y >> d >> g;

        vector<int> v;
        v.push_back(d%4);
        board[y][x]=1;

        while(g--){
            int vSize = v.size();
            // 세대가 증가할 때마다 기존 세대의 방향(숫자)을 뒤에서부터 1을 더한 방향(숫자)을 추가
            // 0: 0
            // 1: 0, 1
            // 2: 0, 1, 2, 1
            // 3: 0, 1, 2, 1, 2, 3, 2, 1
            for(int j = vSize-1; j >= 0; j--)
            v.push_back((v[j]+1)%4);
        }

        for(int i = 0; i < v.size(); i++){
            int dir = v[i];
            if(dir == 0) x++;
            else if(dir == 1) y--;
            else if(dir == 2) x--;
            else if(dir == 3) y++;
            board[y][x] = 1;
        }
    }
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(!board[i][j]) continue;
            if(board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    cout << cnt;
}

