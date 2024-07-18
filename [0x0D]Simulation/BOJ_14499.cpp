// 1H 20M
// 구현은 30분정도 밖에 안걸렸지만 주사위 이해 하는게 좀 오래걸린문제
// 조금 더 깔끔한 코드가 있겠지만 직관적으로 바로 구현가능해보였음

#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int dice[6]={0,};
int N,M;
int x,y;
int K;
int order;

/*
다이스 모양 

  2
4 1(위) 3
  5
  6(밑)

*/

// dice[2]== 위, dice[5]==밑

void emv(){
    int tmp=dice[3];
    int tmp2=dice[5];
    dice[3]=dice[2];
    dice[2]=dice[1];
    dice[1]=tmp2;
    dice[5]=tmp;
}
void wmv(){
    int tmp=dice[1];
    int tmp2=dice[5];
    dice[1]=dice[2];
    dice[2]=dice[3];
    dice[3]=tmp2;
    dice[5]=tmp;
}

void nmv(){
    int tmp=dice[0];
    dice[0]=dice[2];
    dice[2]=dice[4];
    dice[4]=dice[5];
    dice[5]=tmp;
}

void smv(){
    int tmp=dice[5];
    dice[5]=dice[4];
    dice[4]=dice[2];
    dice[2]=dice[0];
    dice[0]=tmp;
}

void cover(){
    if(board[x][y]==0)board[x][y]=dice[5];
    else {
        dice[5]=board[x][y];
        board[x][y]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    for(int i=0; i<K; i++){
        cin >> order;
        if(order==0){
            cout << dice[2] << '\n';
        }
        else if(order==1){
            if(y+1>=M)continue;
            emv();
            y++;
            cover();
            cout << dice[2] << '\n';
        }
        else if(order==2){
            if(y-1<0)continue;
            wmv();
            y--;
            cover();
            cout << dice[2] << '\n';
        }
        else if(order==3){
            if(x-1<0)continue;
            nmv();
            x--;
            cover();
            cout << dice[2] << '\n';
        }
        else{
            if(x+1>=N)continue;
            smv();
            x++;
            cover();
            cout << dice[2] << '\n';
        }
    }
}