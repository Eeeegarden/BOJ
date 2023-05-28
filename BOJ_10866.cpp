//덱을 배열로 구현

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int X){
    dat[--head]=X;
}

void push_back(int X){
    dat[tail++]=X;
}

void pop_front(){
    cout << dat[head++] << '\n';
}

void pop_back(){
    cout << dat[--tail] << '\n';
}

int size(){
    return tail-head;
}

int empty(){
    return !bool(size());
}


int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    while(num--){
        string S;
        cin >> S;

        if(S == "push_front"){
            int n;
            cin >> n;
            push_front(n);
        }
        else if(S == "push_back"){
            int n;
            cin >> n;
            push_back(n);
        }
        else if(S == "pop_front"){
            if(empty()==0)pop_front();
            else cout << "-1" << '\n';
        }
        else if(S == "pop_back"){
            if(empty()==0)pop_back();
            else cout << "-1" << '\n';
        }
        else if(S == "size"){
            cout << size() << '\n';
        }
        else if(S == "empty"){
            cout << empty() << '\n';
        }
        else if (S == "front"){
            if(empty()==0)cout << front() << '\n';
            else cout << "-1" << '\n';
        }
        else if (S == "back"){
            if(empty()==0)cout << back() << '\n';
            else cout << "-1" << '\n';
        }
    }
}
