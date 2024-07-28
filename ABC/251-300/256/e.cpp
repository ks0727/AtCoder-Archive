#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  vector<ll> c(n);
  rep(i,n) cin >> x[i],x[i]--;
  rep(i,n) cin >> c[i];
  vector<int> order(n,-1);
  vector<bool> done(n);
  ll ans = 0;
  auto f = [&](auto f, int v,vector<int> visited)->void{
    if(done[v]){
      for(int x : visited) done[x] = true;
      return;
    } 
    if(order[v] != -1){
      int depth = (int)visited.size() - order[v];
      ll now = 1e18;
      for(int x : visited){
        done[x] = true;
      } 
      while(depth-- && !visited.empty()){
        now = min(now,c[visited.back()]);
        visited.pop_back();
      }
      if(now != 1e18) ans += now;
      visited = {};
      return;
    }
    order[v] = (int)visited.size();
    visited.push_back(v);
    f(f,x[v],visited);
    return;
  };
  rep(i,n){
    if(done[i]) continue;
    f(f,i,vector<int>{});
  }
  cout << ans << endl;
  return 0;
}

