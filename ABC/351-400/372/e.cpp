#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

struct UnionFind{
  int n;
  vector<int> rank,par;
  vector<set<int> > groups;
  UnionFind(int n):n(n),rank(n,1),par(n),groups(n){
    for(int i=0;i<n;i++) par[i] = i,groups[i].insert(i);
  };
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  int merge(int a, int b){
    int na = root(a);
    int nb = root(b);
    if(na == nb) return na;
    if(rank[na] > rank[nb]) swap(na,nb);
    rank[nb] += rank[na];
    par[na] = par[nb];
    for(int x:groups[na]) groups[nb].insert(x);
    groups[na].clear();
    return nb;
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
  void show(){
    cout << "---------------show begin-------------------"<< endl;
    for(int i=0;i<n;i++){
      if(groups[i].size() == 0) continue;
      cout << "------------------------------" << endl;
      for(int x : groups[i] ) cout << x << ' '; cout << endl;
    }
    cout << "---------------show end---------------------" << endl;
  }
};
int main(){
    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    for(int qi=0;qi<q;qi++){
      int type;
      cin >> type;
      if(type == 1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        if(!uf.same(u,v)) uf.merge(u,v);
      }else{
        int v,k;
        cin >> v >> k;
        v--;
        int lv = uf.root(v);
        if(uf.groups[lv].size() < k) cout << -1 << '\n';
        else{
          auto it = uf.groups[lv].rbegin();
          for(int i=0;i<k-1;i++) it++;
          cout << *it+1 << '\n';
        }
      }
    }
    return 0;
}
