#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  const int INF = 1001001001;
  vector<int> dist(n,INF);
  dist[0] = 0;
  auto dfs = [&](auto dfs, int v, int p=-1)->void{
    if(p!=-1)dist[v] = dist[p]+1;
    for(int u : g[v]){
      if(u == p) continue;
      dfs(dfs,u,v);
    }
  };
  dfs(dfs,0);
  int sv =0;
  int mx = 0;
  for(int i=0;i<n;i++){
    if(dist[i] > mx){
      mx = dist[i];
      sv = i;
    }
  }
  for(int i=0;i<n;i++) dist[i] = INF;
  dist[sv] = 0;
  dfs(dfs,sv);
  int ans = 0;
  for(int i=0;i<n;i++) ans = max(ans,dist[i]);
  cout << ans + 1 << endl;
  return 0;
}

