#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
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
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void merge(int a,int b){
    a = root(a);
    b = root(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a,b);
    rank[b] += rank[a];
    par[a] = b;
  }
  bool same(int a, int b){
    return root(a) == root(b);
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<int> nxt(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(uf.same(a,b)){
      cout << "No" << endl;
      return 0;
    }else{
      uf.merge(a,b);
      nxt[a]++;
      nxt[b]++;
      if(nxt[a] >= 3 || nxt[b] >= 3){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}


