#include <iostream>
#include<cassert>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  string ns = to_string(n);
  long long ans = 0;
  long long add = 1;
  if(ns.size() >= 3){
    long long now = 0;
    for(int i=1;i<ns.size()-1;i++){
      now = ns[i]-'0';
      add *= now;
    }
  }
  for(int i=1;i<=n;i++){
    string s = to_string(i);
    char a = s[0]; char b = s[s.size()-1];
    if(s.size() == 1) ans++;
    else if(s.size() == 2){
      if(a == b) ans += 2;
      else{
        reverse(s.begin(),s.end());
        int now = stoi(s);
        if(now <= n) ans++;
      }
    }
    else{
      assert(s.size() >= 3);
      if(s.size() < ns.size()){
        if(a == b){
          ans += 2;
          for(int i=0;i<s.size()-2;i++){
            long long now = 1;
            for(int j=0;j<i+1;j++) now*=10;
            ans += now;
          }
        }else{
          ans++;
          for(int i=0;i<s.size()-2;i++){
            long long now = 1;
            for(int j=0;j<i+1;j++) now*=10;
            ans += now;
          }
        }
      }else{
        assert(s.size() == ns.size());
        if(a == b){
            ans += 2;
            for(int i=0;i<s.size()-3;i++){
              long long now = 1;
              for(int j=0;j<i+1;j++) now*=10;
              ans += now;
            }
            ans += add;
        }else{
          ans++;
          for(int i=0;i<s.size()-3;i++){
              long long now = 1;
              for(int j=0;j<i+1;j++) now*=10;
              ans += now;
          }
          ans += add;
        }
      }
    }
  }
  cout << ans << endl;
}
