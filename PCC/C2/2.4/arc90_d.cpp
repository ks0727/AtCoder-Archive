#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<int,ll>;

struct Edge{
  int to; ll cost;
  Edge(int to, ll cost):to(to),cost(cost){}
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<Edge> > g(n);
  rep(i,m){
    int l,r; ll d;
    cin >> l >> r >> d;
    l--; r--;
    g[l].emplace_back(r,d);
    g[r].emplace_back(l,-d);
  }
  vector<bool> seen(n);
  vector<ll> x(n,0);
  bool ans = true;
  rep(i,n){
    auto dfs = [&](auto dfs, int v,ll now)->void{
      seen[v] = true;
      for(auto e : g[v]){
        if(seen[e.to]){ //すでに見たことがある場合
          if(x[v] + e.cost != x[e.to]) ans = false; 
        }else{
          x[e.to] = x[v]+e.cost;
          dfs(dfs,e.to,now+e.cost);
        }
      }
    };
    if(!seen[i]){
      //cout << i << endl;
      if(!ans){
        cout << "No" << endl;
        return 0;
      }else dfs(dfs,i,0);
    }
  }
  //rep(i,n) cout << x[i] << ' '; cout << endl;
  if(ans) cout << "Yes" << endl;
  else  cout << "No" << endl;
  return 0;
}