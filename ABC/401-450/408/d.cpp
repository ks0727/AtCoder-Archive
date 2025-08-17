#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<char,int> > ps;
  for(int i=0;i<n;i++){
    if(ps.size() == 0){
      ps.emplace_back(s[i],1);
    }else{
      if(ps.back().first == s[i]) ps.back().second++;
      else ps.emplace_back(s[i],1);
    }
  }
  if(ps.size() <= 1){
    cout << 0 << endl;
    return;
  }
  int cnto=0,cntz=0;
  for(int i=0;i<ps.size();i++){
    if(ps[i].first == '1') cnto+=ps[i].second;
    else cntz += ps[i].second;
  }
  int ans = 1001001001;
  int nowo = 0, nowz = 0;
  for(int i=0;i<ps.size();i++){
    if(ps[i].first == '1'){
      int now = min(nowo,nowz) + min(cnto-nowo-ps[i].second,cntz-nowz);
      ans = min(now,ans);
      nowo += ps[i].second;
    }else{
      nowz += ps[i].second;
    }
  }
  cout << ans << endl;
  return; 
}

int main(){
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}

