#include <iostream>
#include <vector> 
#include <set>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  for(int i=0;i<m;++i){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(b);
  }
  vector<int> seen(n);
  auto dfs = [&](auto dfs, int v, int p =-1){
    seen[v] = true;
    for(int u: g[v]){
      if(u == p) continue;
      cout << u << endl;
      if(seen[u]) return true;
      if(dfs(dfs,u,v)) return true;
    }
    return false;
  };

int ans = 0;
      
  for(int i=0;i<(n);i++){
    if(seen[i]) continue;
    if(g[i].size() != 1) continue;
    if(!dfs(dfs,i,-1)) ans++;
  } 
  cout << ans << endl;
  return 0;
}

