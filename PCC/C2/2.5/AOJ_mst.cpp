#include <iostream>
#include <tuple>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using P = tuple<ll,int,int>;
struct UnionFind{
  int n;
  int par[10000];
  int size[10000];
  UnionFind(int n):n(n){
    for(int i=0;i<n;i++) par[i] = i,size[i]=0;
  }
  int root(int x){
    if(par[x] == x) return x;
    return  par[x] = root(par[x]);
  }
  void merge(int x,int y){
    int px = root(x);
    int py = root(y);
    if(px == py) return;
    if(size[px] > size[py]){
      par[py] = px;
    }else if(size[px] < size[py]){
      par[px] = py;
    }else{
      size[px]++;
      par[py] = px;
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
};

struct Edge{
  int to; ll cost;
  Edge(int to, ll cost):to(to),cost(cost){}
};
int main(){
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<vector<Edge> > g(n);
  vector<P> es;
  for(int i=0;i<m;i++){
    int a,b; ll w;
    cin >> a >> b >> w;
    g[a].emplace_back(b,w);
    g[b].emplace_back(a,w);
    es.emplace_back(w,a,b);
  }
  sort(es.begin(),es.end());
  ll ans = 0;
  for(P e : es){
    auto [c,u,v] = e;
    if(uf.same(u,v)) continue;
    uf.merge(u,v);
    ans += c;
  }
  cout << ans << endl;
  return 0;
}

