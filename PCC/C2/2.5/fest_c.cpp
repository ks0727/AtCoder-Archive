#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  int n,m;
  cin >> n >> m;
  vector<set<int> > g(n);
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  ll ans = 0;
  auto dfs = [&](auto dfs, int v, int now, int depth)->void{
    if(depth == 3){
      if(!g[now].count(v)){
        ans++;
        g[now].insert(v);
        g[v].insert(u);
        dfs(dfs,v,v,0);
        dfs(dfs,now,now,0);
        for(int u : g[v]) dfs(dfs,u,u,0);
        for(int u : g[now]) dfs(dfs,now,now,0);
      }
      return;
    }
    for(int u : g[v]){
      
  return 0;
}

