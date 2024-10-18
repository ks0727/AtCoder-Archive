#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
using P = pair<int,int>;
using T = tuple<int,int,int>;
struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n):n(n),par(n),rank(n,1){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x)
  {
    if(x == par[x]) return x;
    else return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    a = root(a); b = root(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a,b);
    rank[b] += rank[a];
    par[a] = par[b];
  }
  bool same(int a,int b){return root(a) == root(b);}
};
int main(){
  int n,m,q;
  cin >> n >> m >> q;
  vector<T> es;
  UnionFind uf(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin >> a >>b >> c;
    a--; b--;
    es.emplace_back(c,a,b);
  }
  sort(es.begin(),es.end());
  vector<int> used;
  for(int i=0;i<es.size();i++){
    auto [c,a,b] = es[i];
    if(uf.same(a,b)) continue;
    used.push_back(i);
    uf.merge(a,b);
  } 
  vector<vector<P> > g(n);
  vector<vector<int> > dist(n,vector<int>(n));
  for(int i=0;i<used.size();i++){
    auto [c,a,b] = es[used[i]];
    g[a].emplace_back(b,c);
    g[b].emplace_back(a,c);
    dist[a][b] = c;
    dist[b][a] = c;
  }
  while(q--){
    int a,b,w;
    cin >> a >> b >> w;
    a--; b--;
    vector<int> need;
    vector<bool> seen;
    auto dfs = [&](auto dfs, int v, int p=-1)->void{
      need.push_back(v);
      seen[v] = true;
      if(v == b) return;
      for(auto [u,nc] : g[v]){
        if(u == p) continue;
        if(seen[u]) continue;
        if(v == a && u == b) continue;
        dfs(dfs,u,v);
        need.pop_back();
      }
      return;
    };
    bool use = false;
    for(int i=0;i<need.size()-1;i++){
      if(w < dist[need[i]][need[i+1]]){
        use = true;
        break;
      }
    }
    if(use) cout << "Yes" << endl;
    else cout << "No" << endl;
   } 
  return 0;
}

