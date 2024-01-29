// 푸는중
// 하루 이틀 걸려도 무조건 구현해보기
// cctv 최대개수 8개 이하 , 각 cctv 탐색 최대 4가지경우의수
// --> 백트래킹쓰면 최대 4^8 -> 약65000개 밖에안됨 ㄱㄱ
// 5번 cctv 아니면 배열에 넣어서 next_permutation 으로 순서 정해서 다 돌려보기 ?
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N,M;
int m[10][10];
int vis[10][10];
vector<pair<int,int>> arr;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

//상하좌우 다돌림
void cctv5(int i, int j){
    queue<pair<int,int>> Q;
    for(int dir=0; dir<4; dir++){
        int cnt=0;
        Q.push({i,j});
        vis[i][j]=1;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || ny<0 || nx>=N || ny>=M)continue;
            if(m[nx][ny]==6)continue;
            if(vis[nx][ny]!=0)continue;
            vis[nx][ny]=1;
            if(cnt<=vis[nx][ny])cnt=vis[nx][ny];
            Q.push({nx,ny});
        }
    }
}

void cctv2(int i, int j){
    int c_vis[10][10]
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> m[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(m[i][j]==5)cctv5(i,j);
            if(m[i][j]!=0 && m[i][j]<=4)arr.push_back({i,j});
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }

}


    // for(int dir=0; dir<4; dir++){
    //     vector<bool> v(4-dir,false);
    //     v.insert(v.end(),dir,true);
    //     cout << "----" << dir << "개----\n";
    //     do{
    //         for(int k=0; k<4; k++){
    //             if(v[k])cout << k ;
    //         }
    //         cout << '\n';
    //     }while(next_permutation(v.begin(),v.end()));
    // }
