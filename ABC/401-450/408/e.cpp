#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<long long,int>> > g(n);
  for(int i=0;i<m;i++){
    int a,b; long long c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(c,b);
    g[b].emplace_back(c,a);
  }
  long long ans = 1e18;
  vector<bool> seen(n);
  auto dfs = [&](auto dfs, int v, long long now)->void{
    if(v == n-1){
        ans = min(ans,now);
        return;
    }
    seen[v] = true;
    for(auto [c,u] : g[v]){
      if(seen[u]) continue;
      dfs(dfs,u,c|now);
    }
    seen[v] = false;
  };
  dfs(dfs,0,0);
  cout << ans << endl;
  return 0;
}

