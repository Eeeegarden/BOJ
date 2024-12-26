// 몇몇케이스 시간초과
// 이분탐색 배우고 다시..

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long level=1;
    long long answer = 0;
    while(answer == 0){
        bool ischeck[300002]={0,};
        for(int i=0; i<diffs.size(); i++){
            if(diffs[i]>level){
                if(ischeck[i]==0){
                    answer += (times[i]+times[i-1])*(diffs[i]-level) + times[i];
                }
                else {
                    answer += times[i];
                }
            }
            else {
                answer += times[i];
            }
            if(answer>limit){
                level++;
                answer=0;
                break;
            }
        }
    }
    answer=level;
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> diffs = {1,5,3};
    vector<int> times = {2,4,7};
    int limit = 30;

    cout << solution(diffs, times, limit);
}
