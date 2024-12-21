#include <iostream>
#include<vector>
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
    a = root(a); b = root(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a,b);
    rank[b] += rank[a];
    par[a] = b;
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};
int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<T> es;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    es.emplace_back(c,a,b);
  }
  sort(es.begin(),es.end());
  vector<int> a(n),b(n);
  vector<bool> isa(n);
  for(int i=0;i<k;i++){
    int x;
    cin >> x; x--;
    a[x]++;
    isa[x] = true;
  }
  for(int i=0;i<k;i++){
      int x;
      cin >> x; x--;
      b[x]++;
  }
  long long ans = 0;
  UnionFind uf(n);
  for(auto [c,u,v] : es){
    if(uf.same(u,v)) continue;
    u = uf.root(u); v = uf.root(v);
    int sumA = a[u] + a[v];
    int sumB = b[u] + b[v];
    int dec = min(sumA,sumB);
    ans += (long long) dec*c;
    sumA -= dec; sumB -= dec;
    uf.merge(u,v);
    int l = uf.root(u);
    a[l] = sumA; b[l] = sumB;
  }
  cout << ans << endl;
  return 0;
}

