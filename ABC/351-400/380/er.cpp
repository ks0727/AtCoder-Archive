#include <iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n):n(n),par(n),rank(n,1){
    for(int i=0;i<n;i++){
       par[i] = i;
     }
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
  int size(int a){
    int na = root(a);
    return rank[na];
  }
};
int main(){
  int n,Q;
  cin >> n >> Q;
  UnionFind uf(n+2);
  vector<int> vtoc(n+2),cnt(n+2,1);
  vector<int> lb(n+2),rb(n+2);
  for(int i=0;i<n+2;i++){
    vtoc[i] = i;
    lb[i] = i;
    rb[i] = i;
  }
  while(Q--){
    int type;
    cin >> type;
    if(type == 1){
      int x,c;
      cin >> x >> c;
      cnt[vtoc[uf.root(x)]] -= uf.size(x);
      vtoc[uf.root(x)] = c;
      cnt[vtoc[uf.root(x)]] += uf.size(x);
      {
        int left = lb[uf.root(x)]-1;
        int li = uf.root(left);
        int ll = lb[li];
        int rr = rb[uf.root(x)];
        if(vtoc[li] == c){
          uf.merge(li,x);
          lb[uf.root(x)] = ll;
          rb[uf.root(x)] = rr;
        }
      }
      {
        int right = rb[uf.root(x)]+1;
        int ri = uf.root(right);
        int rr = rb[ri];
        int ll = lb[uf.root(x)];
        if(vtoc[ri] == c){
          uf.merge(ri,x);
          lb[uf.root(x)] = ll;
          rb[uf.root(x)] = rr;
        }
      }
    }
    else{
      int c;
      cin >> c;
      cout << cnt[c] << endl;
    }
  }
}
      

