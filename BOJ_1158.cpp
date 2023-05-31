#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    
    // 1~n 이 들어갈 리스트 L
    // 요세푸스 순열을 저장하는 리스트 Y
    list<int> L={};
    list<int> Y={};

    for(int i=1; i<=n; i++){
        L.insert(L.end(),i);
    }

    auto cursor=L.begin();

    //요세푸스 순열 생성
    //예외처리(커서가 리스트 끝인경우, 리스트가 두개일경우)
    while(n--){
        for(int i=0; i<k-1; i++){
            //리스트 이동중 커서가 리스트 끝일경우 리스트 맨앞으로 이동
            if(cursor == L.end())cursor=L.begin();
            else cursor++;
            //리스트가 두개남아있는경우
            if(cursor == L.end())cursor=L.begin();
        }
        Y.push_back(*cursor);
        cursor = L.erase(cursor);
        //리스트가 두개남아있는경우
        if(cursor == L.end())cursor=L.begin();

    }

    // 순열 출력
    for(auto c : Y){
        if( c == Y.front())cout << '<' ; 
        cout << c ;
        if( c != Y.back())cout << ", ";
        else cout << '>';
    }
}