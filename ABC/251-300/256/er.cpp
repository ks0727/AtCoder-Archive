#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using ll = long long;
int x[2<<17];
ll c[2<<17];
bool seen[2<<17];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;++i) cin >> x[i],x[i]--;
  for(int i=0;i<n;++i) cin >> c[i];
  vector<int> dim(n);
  for(int i=0;i<n;++i) dim[x[i]]++;
  dsu uf(n);
  ll ans = 0;
  for(int i=0;i<n;++i){
    if(seen[i]) continue;
    if(dim[i] < 2) continue;
    ll now = 1e18;
    int v = i;
    do{
      seen[v] = true;
      now = min(c[v],now);
      v = x[v];
    }while(i != v);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}

