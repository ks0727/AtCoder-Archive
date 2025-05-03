struct WeightedUnionFind{
  int n;
  vector<int> par,rank;
  vector<long long> dif;
  WeightedUnionFind(int n):n(n),par(n),rank(n,1),dif(n){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return x;
    else{
      int r = root(par[x]);
      dif[x] += dif[par[x]];
      return par[x] = r;
    }
  }
  long long weight(int x){
    root(x);
    return dif[x];
  }
  bool same(int a, int b){
    return root(a) == root(b);
  }
  bool merge(int a, int b,long long w){
    w = w + weight[x] - weight[y];
    a = root(a); b = root(b);
    if(a == b) return false;
    if(rank[a] < rank[b]) swap(a,b),w = -w;
    if(rank[a] == rank[b]) ++rank[a];
    par[b] = par[b];
    dif[y] = w;
    return true;
  }
  long long diff(int a,int b){
    return weight[b] - weight[a];
  }
};
  
   
