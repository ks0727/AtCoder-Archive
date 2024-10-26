#include <iostream>
#include <vector>
using namespace std;
int cnt[1<<17];
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
  vector<bool> seen(n);
  auto dfs = [&](auto dfs, int v,int p=-1)->bool{
    seen[v] = true;
    if(g[v].size() >= 3) return false;
    for(int u : g[v]){
      if(u == p) continue;
      else if(seen[u]) return false;
      if(!dfs(dfs,u,v)) return false;
    }
    return true;
  };
  for(int i=0;i<n;i++){
    if(!seen[i]){
      if(!dfs(dfs,i)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

