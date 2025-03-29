#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<long long,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<P> > g(n);
  for(int i=0;i<m;i++){
    int u,v; long long w;
    cin >>u >> v >> w;
    u--; v--;
    g[u].emplace_back(w,v);
    g[v].emplace_back(w,u);
  }
  long long ans = 9e18;
  auto dfs = [&](auto dfs, int v, long long now, vector<bool> visited)->void{
    if(v == n-1){
      ans = min(ans,now);
      return;
    }
    visited[v] = true;
    for(auto [c,u] : g[v]){
      if(visited[u]) continue;
      dfs(dfs,u,now^c,visited);
    }
    visited[v] = false;
  };
  dfs(dfs,0,(long long)0,vector<bool>(n));
  cout << ans << endl;
}
      

