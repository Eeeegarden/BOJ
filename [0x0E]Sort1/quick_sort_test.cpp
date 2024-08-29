#include <bits/stdc++.h>
using namespace std;

int n = 8;
int arr[1000001] = {6, -8, 1, 12, 8, 3, 7, -7};

void quick_sort(int st, int en){
    if(en<=st+1)return;
    int pivot=st;
    int lp=pivot+1;
    int rp=en-1;
    while(1){
        while(lp<=rp && arr[lp]<=arr[pivot])lp++;
        while(lp<=rp && arr[rp]>arr[pivot])rp--;
        if(lp>rp)break;
        swap(arr[lp],arr[rp]);
    }
    swap(arr[pivot],arr[rp]);
    quick_sort(st,rp);
    quick_sort(rp+1,en);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    quick_sort(0,n);
    for(int i=0; i<n; i++) cout << arr[i] << ' ';
}