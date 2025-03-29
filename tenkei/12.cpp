#include <iostream>
#include<vector>
using namespace std;
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
struct UnionFind{
  int n;
  vector<int> par,rank;
  UnionFind(int n): n(n),rank(n,1),par(n){
    for(int i=0;i<n;i++) par[i] = i;
  }
  int root(int x){
    if(x == par[x]) return x;
    return par[x] = root(par[x]);
  }
  bool same(int a,int b){
    return root(a) == root(b);
  }
  void merge(int a,int b){
    int na = root(a); int nb = root(b);
    if(na == nb) return;
    if(rank[na] > rank[nb]) swap(na,nb);
    rank[nb] += rank[na];
    par[na] = par[nb];
  }
};

int main(){
  int h,w;
  cin >> h >> w;
  UnionFind uf(h*w);
  vector<vector<bool> > red(h,vector<bool>(w));

  int q;
  cin >> q;
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int r,c;
      cin >> r >> c;
      r--; c--;
      red[r][c] = true;
      for(int d=0;d<4;d++){
        int ni = r+di[d];
        int nj = c+dj[d];
        if(ni < 0  || nj < 0 || ni >= h || nj >= w) continue;
        if(red[ni][nj]){
          uf.merge(r*w+c,(ni*w)+nj);
        }
      }
    }else{
      int ra, ca,rb,cb;
      cin >> ra >> ca >> rb >> cb;
      ra--,ca--,rb--,cb--;
      if(red[ra][ca] && red[rb][cb] && uf.same(ra*w+ca,rb*w+cb)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}

