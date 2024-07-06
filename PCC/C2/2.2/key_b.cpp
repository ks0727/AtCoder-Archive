#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
  int n;
  cin >> n;
  vector<P> evs;
  for(int i=0;i<n;++i){
    ll x,l;
    cin >> x >> l;
    ll start = x-l;
    ll end = x+l;
    evs.push_back(P(end,start));
  }
  sort(evs.begin(),evs.end());
  int ans = 1;
  P now = evs[0];
  for(int i=1;i<n;++i){
    auto [ei,si] = evs[i];
    if(now.first > si) continue;
    ans++;
    now = P(ei,si);
  }
  cout << ans << endl;
  return 0;
}

