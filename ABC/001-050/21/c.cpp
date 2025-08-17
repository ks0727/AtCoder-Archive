#include <iostream>
#include<vector>
#include<algorithm>
#include<atcoder/modint>
#include<queue>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
  int n;
  cin >> n;
  int a,b;
  cin >> a >> b;
  a--; b--;
  int m;
  cin >> m;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<mint> cnt(n);
  vector<int> dist(n,1001001001);
  dist[a] = 0;
  cnt[a] = 1;;
  queue<int> q;
  q.push(a);
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u : g[v]){
      if(dist[u] != 1001001001 && dist[u] != dist[v] + 1) continue;
      if(dist[u] == dist[v]+1){
        cnt[u]+=cnt[v];
        continue;
      }
      cnt[u] = cnt[v];
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
  cout << cnt[b].val() << endl;
  return 0;
}

