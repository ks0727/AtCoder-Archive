#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using T = tuple<int,int,int,int>;

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
    par[na] = par[nb];
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};


int main(){
  int n,m,q;
  cin >> n>> m >> q;
  vector<T> es;
  for(int i=0;i<m+q;i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(c,a,b,i);
  }
  vector<bool> ans(q);
  UnionFind uf(n);
  sort(es.begin(),es.end());
  for(int i=0;i<m+q;i++){
    auto [c,a,b,idx] = es[i];
    if(idx < m){
      uf.merge(a,b);
    }else{
      if(!uf.same(a,b)){
        ans[idx-m] = true;
      }
    }
  }
  for(int i=0;i<q;i++) {
    if(ans[i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

