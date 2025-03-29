#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int> > > g(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
  }
  bool ok = true;
  vector<int> ans(n);
  for(int k=0;k<30;k++){
    vector<int> color(n,-1);
    vector<vector<int> > vs(2);
    for(int sv=0;sv<n;sv++){
      if(color[sv] == -1){
        auto dfs = [&](auto dfs,int v, int c)->void{
          if(color[v] != -1){
            if(color[v] != c) ok = false;
            return;
          }
          color[v] = c;
          vs[c].push_back(v);
          for(auto [to,z] : g[v]){
            dfs(dfs,to,c^(z>>k&1));
          }   
        };
        dfs(dfs,sv,0);
        if(vs[0],size < vs[1].size()) swap(vs[0],vs[1]);
        for(int v:vs[1]) ans[v] |= 1<<k;
      }
    }
  }
  if(!ok){
    cout << -1 << endl;
    return 0;
  }
  for(int i=0;i<n;i++) cout << ans[i] << ' '; cout << endl;
  return 0;
}

