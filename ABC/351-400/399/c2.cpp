#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans = 0;
  vector<bool> seen(n);
  for(int i=0;i<n;i++){
    if(seen[i]) continue;
    int ce = 0;
    int cv = 0;
    auto dfs = [&](auto dfs, int v, int p=-1)->void{
      seen[v] = true;
      ce += g[v].size();
      for(int u : g[v]){
        if(!seen[u]) continue;
        dfs(dfs,u,v);
        cv++;
      }
    };
    dfs(dfs,i);
    ans += ce - cv + 1;
  }
  cout << ans << endl;
  return 0;
}

