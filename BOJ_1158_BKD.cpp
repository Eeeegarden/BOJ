// Authored by : OceanShape
// 야매연결리스트 활용
#include <bits/stdc++.h>
using namespace std;

int N,K,len=0;
int pre[5005];
int nxt[5005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K ;
    vector<int> V;

    //연결리스트 처음 노드와 마지막 노드가 서로를 가리키도록 지정
    for(int i=1; i<=N; i++){
        pre[i]=(i==1) ? N : i-1;
        nxt[i]=(i==N) ? 1 : i+1;
        len++;
    }

    int i=1;
    //연결 리스트를 순회하면서 순열 생성
    for(int cur=1; len!=0; cur=nxt[cur]){
        if(i==K){
            pre[nxt[cur]]=pre[cur];
            nxt[pre[cur]]=nxt[cur];
            V.push_back(cur);
            i=1;
            --len;
        }
        else ++i;
    }

    cout << "<" ; 
    for(size_t i=0; i<V.size(); ++i){
        cout << V[i];
        if(i!=V.size()-1)cout << "," ;
    }
    cout << ">" ;
}

