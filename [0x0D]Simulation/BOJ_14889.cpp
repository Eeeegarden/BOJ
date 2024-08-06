// 50M

// 쉬운문제
// 순열 이용해서 팀 조합 구해서 팀원의 쌍 능력치 구해주면됨
#include <bits/stdc++.h>
using namespace std;

int N;
int S[22][22];
int ans=INT_MAX;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> S[i][j];
        }
    }
    vector<int> tmp;
    for(int i=0; i<N; i++){
        tmp.push_back(i);
    }
    vector<int> brute(N,1);
    fill(brute.begin(),brute.begin()+N/2,0);
    do{
        vector<int> team1;
        vector<int> team2;
        int sum1=0; int sum2=0;
        // team1과 team2로 팀나눔
        for(int i=0; i<N; i++){
            if(brute[i]==1)team1.push_back(tmp[i]);
            else team2.push_back(tmp[i]);
        }
        // 차례로 쌍의 능력치 합연산
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2; j++){
                sum1+=S[team1[i]][team1[j]]+S[team1[j]][team1[i]];
                sum2+=S[team2[i]][team2[j]]+S[team2[j]][team2[i]];
            }
        }
        ans=min(abs(sum1-sum2),ans);
    }while(next_permutation(brute.begin(),brute.end()));

    cout << ans;
}