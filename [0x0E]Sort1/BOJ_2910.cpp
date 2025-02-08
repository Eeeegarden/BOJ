// 들어온 순서를 저장하는 seq 벡터를 도입했지만 stable_sort 활용하면 순서 보장이 됨
// seq 및 line:14 생략 가능


#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int,int>> v;
vector<int> seq;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.X == b.X) return find(seq.begin(), seq.end(), a.Y) < find(seq.begin(), seq.end(), b.Y);
    return a.X > b.X;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,C;

    cin >> N >> C;

    for(int i=0; i<N; i++){
        int num;
        bool chk=false;
        cin >> num;
        for(auto &c : v){
            if(c.Y == num){
                c.X++;
                chk=true;
                break;
            }
        }
        if(chk==false) {
            v.push_back({1,num});
            seq.push_back(num);
        }
    }
    sort(v.begin(), v.end(), cmp);

    for(auto &c : v) {
        while(c.X--) cout << c.Y << ' ';
    }

}
