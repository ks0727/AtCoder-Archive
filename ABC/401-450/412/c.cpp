#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int> s(n);
  for(int i=0;i<n;i++) cin >> s[i];
  //2倍以下で最大のものを見つけていく
  //それでs[n-1]に到達できればクリア
  int ans = 2;
  int now = s[0];
  bool ok = false;
  int end = s[n-1];
  sort(s.begin(),s.end());
  while(true){
    if(now*2 >= end){
      ok = true;
      break;
    }
    auto it = upper_bound(s.begin(),s.end(), now*2);
    it--;
    if(*it == now) break;
    now = *it;
    ans++;
  }
  if(ok) cout << ans << endl;
  else cout << -1 << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--) solve();
  return 0;
}

