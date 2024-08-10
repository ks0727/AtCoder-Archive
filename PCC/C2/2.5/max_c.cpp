#include <iostream>
#include <vector>
using namespace std;

struct UnionFind{
  int n;
  int par[2<<17];
  int rank[2<<17];
  UnionFind(int n):n(n){
    for(int i= 0;i<n;i++) par[i] = i;
    for(int i=0;i<n;i++) rank[i] = 0;
  }
  int root(int x){
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
  }
  void merge(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(rank[x] < rank[y]) par[x] = y;
    else{
      par[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
};

int main(){
  int n;
  cin >> n;
  bool ok[2*n];
  for(int i=0;i<2*n;i++) ok[i] = true;
  UnionFind uf(2*n);
  for(int i =0;i<n;i++){
    int a;
    cin >> a;
    a--;
    if((uf.par[i] != i ||uf.par[a+n] != a+n) && !uf.same(i,a+n)){
      ok[uf.root(i)] = false;
    }
    else uf.merge(i,a+n);
    if((uf.par[i+n] != i+n ||uf.par[a] != a) && !uf.same(i,a+n)) ok[uf.root(a)] = false;
    else uf.merge(i+n,a);
  }
  vector<vector<int> > gs(2*n);
  for(int i=0;i<2*n;i++){
    if(!ok[uf.root(i)]) continue;
    gs[uf.root(i)].push_back(i);
  }
  int ans = -1;
  for(int i=0;i<2*n;i++){
    if(gs[i].size() != n) continue;
    int now = 0;
    for(int j=0;j<n;++j){
      if(gs[i][j] >= n) now++;
    }
    now = max(now,n-now);
    ans = max(ans,now);
  }
  cout << ans << endl;
      
  return 0;
}

