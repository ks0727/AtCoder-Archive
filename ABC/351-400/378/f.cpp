#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct UnionFind{
  int n;
  vector<int> par,rank;
  vector<vector<int> > groups;
  UnionFind(int n):n(n),rank(n,1),par(n),groups(n){
    for(int i=0;i<n;i++){
      par[i] = i;
      groups[i].push_back(i);
    }
  }
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    int na = root(a); int nb = root(b);
    if(na == nb) return;
    if(rank[na] > rank[nb]) swap(na,nb);
    for(int x : groups[na]){
      groups[nb].push_back(x);
    }
    groups[na] = {};
    rank[nb] += rank[na];
    par[na] = par[nb];
    return;
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  vector<int> dim(n);
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
    dim[u]++;
    dim[v]++;
  }
  UnionFind uf(n);
  long long ans = 0;
  int sv = -1;
  for(int i=0;i<n;i++) if(dim[i] == 1){
    sv = i;
    break;
  }
  auto dfs = [&](auto dfs,int v,int p=-1)->void{
      for(int u : g[v]){
        if(u == p) continue;
        if(dim[v] == 3 && dim[u] == 3){
          uf.merge(u,v);
        }
        dfs(dfs,u,v);
      }
  };
  dfs(dfs,sv);
  vector<bool> seen(n);
  for(int i=0;i<n;i++){
    if(seen[uf.root(i)]) continue;
    seen[uf.root(i)] = true;
    set<int> st;
    for(int x : uf.groups[uf.root(i)]){
      for(int u : g[x]){
        if(dim[u] == 2) st.insert(u);
      }
    }
    ans += (long long)st.size()*(st.size()-1)/2;
  }
  cout << ans << endl;
  return 0;
}

