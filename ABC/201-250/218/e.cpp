#include <iostream>
#include <vector>
#include<algorithm>
#include<tuple>
using namespace std;
using T = tuple<int,int,int>;
struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n):n(n),par(n),rank(n,1){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(x == par[x]) return x;
    return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    int na = root(a);
    int nb = root(b);
    if(na == nb) return;
    if(rank[na] > rank[nb]) swap(na,nb);
    rank[nb] += rank[na];
    par[na] = nb;
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};
int main(){
  int n,m;
  cin >> n >> m;
  vector<T> es;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(c,a,b);
  }
  long long ans = 0;
  sort(es.begin(),es.end());
  UnionFind uf(n);
  for(int i=0;i<m;i++){
    auto [c,a,b] = es[i];
    if(uf.same(a,b) && c > 0) ans += c;
    else uf.merge(a,b);
  }
  cout << ans << endl;
  return 0;
}

