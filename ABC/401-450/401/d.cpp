#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  for(int i=0;i<n;i++){
    if(s[i] == 'o'){
      if(i != 0 && s[i-1] == '?') s[i-1] = '.';
      if(i != n-1 && s[i+1] == '?') s[i+1] = '.';
    }
  }
  int tot = 0;
  for(int i=0;i<n;i++){
    if(s[i] == '?'){
      tot++;
      i++;
    }else if(s[i] == 'o') tot++;
  }
  if(tot > k) cout << s << endl;
  else if(tot == k){
    int now = 0;
    for(int i=0;i<n;i++){
      if(s[i] == '?'){
        now++;
      }else{
        for(int j=0;j<  
        now = 0;
      

