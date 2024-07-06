#include <iostream>
#include <vector>
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
    g[b].push_back(a);
  }
  int ans = 0;
  vector<bool> seen(n);
  auto dfs =[&](auto dfs,int v,int d)->void{
    seen[v] = true;
    if(d == n-1){
      ans++;
      return;
    }
    for(int u : g[v]){
      if(seen[u]) continue;
      dfs(dfs,u,d+1);
      seen[u] = false;
    }
  };
  dfs(dfs,0,0);
  cout << ans << endl;
  return 0;
}

