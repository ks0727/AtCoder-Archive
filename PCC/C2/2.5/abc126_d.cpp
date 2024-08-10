#include <iostream>
#include <vector>
using namespace std;

struct Edge{
  int to; bool even;
  Edge(int to,bool even):to(to),even(even){}
};

int main(){
  int n;
  cin >> n;
  vector<vector<Edge> > g(n);
  for(int i=0;i<n-1;i++){
    int a,b,w;
    cin >> a >> b >> w;
    a--; b--;
    if(w%2==0){
      g[a].emplace_back(b,true);
      g[b].emplace_back(a,true);
    }else{
      g[a].emplace_back(b,false);
      g[b].emplace_back(a,false);
    }
  }
  vector<int> ans(n,-1);
  auto dfs = [&](auto dfs, int v, bool even)->void{
     if(even) ans[v] = 0;
     else ans[v] = 1;
     for(auto [to,e] : g[v]){
       if(ans[to] != -1) continue;
       if(even && e) dfs(dfs,to,true);
       if(even && !e) dfs(dfs,to,false);
       if(!even && e) dfs(dfs,to,false);
       if(!even && !e) dfs(dfs,to,true);
     }
    return;
  };
  dfs(dfs,0,true);
  for(int i=0;i<n;i++) cout << ans[i] << ' '; cout << endl;
  return 0;
}

