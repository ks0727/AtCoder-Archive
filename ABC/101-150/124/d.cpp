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
    if(ps.size() == 0){
      ps.emplace_back(s[i],1);
    }else{
      auto [c,cnt] = ps.back();ps.pop_back();
      if(c == s[i]) ps.emplace_back(c,cnt+1);
      else{
        ps.emplace_back(c,cnt);
        ps.emplace_back(s[i],1);
      }
    }
  }
  vector<vector<int> > zo(2);
  for(auto [c,cnt] : ps){
    if(c == '0') zo[0].push_back(cnt);
    else zo[1].push_back(cnt);
  } 
  int lo=0,ro=0,lz=0,rz=0;
  int ans = 0;
  int now = 0;
  for(int i=0;i<ps.size();i++){
    auto [c,cnt] = ps[i];
    if(rz < k) {
      if(c == '0'){
        rz++;
        now += cnt;
      }else{
        ro++;
        now += cnt;
      }
    }else{
      if(c == '0'){
        now += cnt;
        rz++;
        if(s[0] == '0'){
          if(lz == 0){
            now -= zo[0][0];
            lz++;
          }else{
            now -= zo[0][lz];
            now -= zo[1][lo];
            lz++;
            lo++;
          }
        }else{
          now -= zo[0][lz];
          now -= zo[1][lo];
          lz++;
          lo++;
        }
      }else{
        now += cnt;
        ro++;
      }
    }
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}

