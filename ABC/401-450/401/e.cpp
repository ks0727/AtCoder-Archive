#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
  queue<int> q;
  const int INF = 1001001001;
  vector<int> min_adj(n,INF);
  min_adj[0] = -1;
  q.push(0);
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u : g[v]){
      if(min_adj[u] == INF){
        min_adj[u] = min(v,min_adj[u]);
        q.push(u);
      }else{
        min_adj[u] = min(v,min_adj[u]);
      }
    }
  }
  for(int i=0;i<n;i++) cout << min_adj[i] << ' '; cout << endl;
  vector<int> ans(n);
  ans[0] = g[0].size();
  for(int i=1;i<n;i++) if(min_adj[i] > i) ans[i] = -1;
  for(int i=0;i<n;i++) cout << ans[i] << '\n';
  return 0;
}

