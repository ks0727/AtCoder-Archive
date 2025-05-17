#include <iostream>
#include<vector>
using namespace std;
using P = pair<long long,int>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<P> > g(n);
  for(int i=0;i<m;i++){
    int u,v; long long w;
    cin >> u >> v >> w;
    u--; v--;
    g[v].emplace_back(-w,u);
    g[u].emplace_back(w,v);
  }
  const long long INF = 2e18; 
  vector<long long> ans(n,INF);
  auto dfs = [&](auto dfs, int v)->void{
    for(auto [c,u] : g[v]){
      if(ans[u] != INF) continue;
      ans[u] = ans[v] + c;
      dfs(dfs,u);
    }
  };
  for(int i=0;i<n;i++){
    if(ans[i] == INF){
      ans[i] = 0;
      dfs(dfs,i);
    }
  }
  for(int i=0;i<n;i++) cout << ans[i] << ' '; cout << endl;
}

