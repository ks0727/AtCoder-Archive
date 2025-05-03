#include <iostream>
#include<vector>
#include<algorithm>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;

struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n):n(n),rank(n,1),par(n){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void merge(int a, int b){
    a = root(a); b = root(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a,b);
    rank[b] += rank[b];
    par[a] = par[b];
  }
  bool same(int a, int b){
    return root(a) == root(b);
  }
};

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin >> s[i];
  int si=-1,sj=-1;
  for(int i=0;i<h;i++)for(int j=0;j<w;j++){
    if(s[i][j] == 'S'){
      si = i;
      sj = j;
    }
  }
  queue<pair<int,int> > q;
  const int di[] = {1,0,-1,0};
  const int dj[] = {0,-1,0,1};
  vector<vector<bool> > seen(h,vector<bool>(w));
  for(int d=0;d<4;d++){
    int ni = si+ di[d]; int nj = sj+dj[d];
    if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
    if(s[ni][nj] == '#') continue;
    q.emplace(ni,nj);
    seen[ni][nj] = true;
  }
  if(q.size() == 1){
    cout << "No" << endl;
    return 0;
  }
  dsu uf(h*w);
  while(!q.empty()){
    auto [i,j] = q.front(); q.pop();
    for(int d=0;d<4;d++){
      int ni = i+ di[d]; int nj = j+dj[d];
      if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if(s[ni][nj] == '#') continue;
      if(ni == si && nj == sj) continue;
      if(seen[ni][nj]) continue;
      seen[ni][nj] = true;
      int id = i*w+j;
      int nid = ni*w+nj;
      uf.merge(id,nid);
      q.emplace(ni,nj);
    } 
  }
  
  vector<pair<int,int> > can;
  for(int d=0;d<4;d++){
    int ni = si+ di[d]; int nj = sj+dj[d];
    if(ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
    if(s[ni][nj] == '#') continue;
    can.emplace_back(ni,nj);
  }
  vector<int> is;
  for(int i=0;i<can.size();i++) is.push_back(i);
  do{
    auto [il,jl] = can[is[0]];
    auto [ir,jr] = can[is[1]];
    int lid = il*w + jl;
    int rid = ir*w + jr;
    if(uf.same(lid,rid)){
      cout << "Yes" << endl;
      return 0;
    }
  }while(next_permutation(is.begin(),is.end()));
  cout << "No" << endl;
}
  

