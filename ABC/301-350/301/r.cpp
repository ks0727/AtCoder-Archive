#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  string s;
  cin >> s;
  long long n;
  cin >> n;
  reverse(s.begin(),s.end());
  long long two = 1;
  long long now = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '1') now += two;
    two *= 2;
  }
  reverse(s.begin(),s.end());
  if(now > n){
    cout << -1 << endl;
    return 0;
  }
  for(int i=0;i<s.size();i++){
    if(s[i] == '?'){
      long long add = 1LL<<(s.size()-i-1);
      if(now + add <= n){
        now += add;
        s[i] = '1';
      }else{
        s[i] = '0';
      }
    }
  }
  reverse(s.begin(),s.end());
  two = 1;
  long long ans = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '1') ans += two;
    two *= 2;
  }
  cout << ans << endl;
}

