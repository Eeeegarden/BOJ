#include <bits/stdc++.h>
using namespace std;

int arr1[26],arr2[26];
int ans=0;
string s1, s2;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  cin >> s1 >> s2;
  for(char c : s1)
    arr1[c-'a']++;
  
  for(char c : s2)
    arr2[c-'a']++;
  
  for(int i=0; i<26; i++)
    if(arr1[i]==arr2[i] && arr1[i]!=0)ans+=arr1[i];
  
  cout << s1.length()-ans;
}