#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct UnionFind{
  int n;
  vector<int> par,rank;
  int size;
  UnionFind(int n):n(n),par(n),rank(n,1){
    size = n;
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    int na = root(a); int nb = root(b);
    if(na == nb) return;
    if(rank[na] > rank[nb]) swap(na,nb);
    rank[nb] += rank[na];
    par[na] = nb;
    size--;
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > ps;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(a > b) swap(a,b);
    ps.emplace_back(a,b);
  }
  sort(ps.begin(),ps.end());
  vector<int> ans(n);
  UnionFind uf(n);
  for(int i=n-1;i>=0;i--){
    while(ps.size() > 0 && ps.back().first == i){
      uf.merge(ps.back().first,ps.back().second);
      ps.pop_back();
    }
    ans[i] = uf.size - i;
  }
  for(int i=1;i<n;i++) cout << ans[i] << endl;
  cout << 0 << endl;
}



