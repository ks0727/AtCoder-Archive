#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for(int i=0;i<n;++i){
    int a;
    cin >> a;
    a--;
    g[i].push_back(a);
    g[a].push_back(i);
  }
  bool ok= true;
  vector<int> color(n,-1);
  auto dfs = [&](auto dfs, int v,int c)->void{
    color[v] = c;
    for(int u : g[v]){
      if(color[u] != -1 && color[u] == c){
        ok = false;
       return;
      }else{
        if(color[u] != -1) continue;
        dfs(dfs,u,c^1);
      }  
     }
    return;
  };
  for(int i=0;i<n;++i){
    if(color[i] ==-1) dfs(dfs,i,0);
  }
  if(!ok) cout << -1 << endl;
  else{
    int ans = 0;
    for(int i=0;i<n;++i){
      if(color[i]) ans++;
    }
    ans = max(ans,n-ans);
    cout << ans << endl;
  }
  return 0;
}

