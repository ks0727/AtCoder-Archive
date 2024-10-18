#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin >> s;
  if(s.size() < 3){
    cout << 0 << endl;
    return 0;
  }
  int n = s.size();
  vector<vector<ll> >  cnt(26);
  ll ans = 0;
  for(int i=0;i<n;i++) cnt[s[i]-'A'].push_back(i);
  for(int i=1;i<n-1;i++){
    for(int j=0;j<26;j++){
      int left = lower_bound(cnt[j].begin(),cnt[j].end(),i) - cnt[j].begin();
      int right = upper_bound(cnt[j].begin(),cnt[j].end(),i) - cnt[j].begin();
      ans += (ll)left*(ll)(cnt[j].size()-right);
    }
  }
  cout << ans << endl;
  return 0;
}

