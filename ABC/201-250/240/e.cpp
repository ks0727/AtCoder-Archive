#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for(int i=0;i<n-1;i++)
  {
    int u,v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> ans(n,-1);
  for(int v : g[0]){
    vector<int> visited;
    auto dfs = [&](auto dfs, int v,int p=-1)->int{
      int res = v;
      visited.push_back(v);
      for(int u : g[v]){
        if(u == p) continue;
        res = min(res,dfs(dfs,u,v));
      }
      return res;
    };
    int val = dfs(dfs,v,0);
    for(int x : visited) ans[x] = val;
  }
  int mx = 0;
  for(int i=0;i<n;i++) mx = max(mx,ans[i]);
  for(int i=0;i<n;i++)
  {
    if(i == 0) cout << 1 << ' ' << mx+1 << endl;
    else cout << ans[i]+1 << ' ' << ans[i]+1 << endl;
  }
  return 0;
}

