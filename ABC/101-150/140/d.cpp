#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<char,int> > ps;
  for(int i=0;i<n;i++){
    if(ps.size() == 0) ps.emplace_back(s[i],1);
    else{
      auto [c,cnt] = ps.back();
      if(c == s[i]){
        ps.pop_back();
        ps.emplace_back(c,cnt+1);
      }else{
        ps.emplace_back(s[i],1);
      }
    }
  }
  int ans = 0;
  for(int i=0;i<ps.size();i++){
    auto [c,cnt] = ps[i];
    ans += cnt-1;
  }
  if(ps.size()/2 <= k){
    ans = n-1;
  }else{
    ans += k*2;
  }
  cout << ans << endl;
  return 0;
}

