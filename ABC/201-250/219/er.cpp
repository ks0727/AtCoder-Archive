#include <iostream>
#include<vector>
#include<set>
using namespace std;
int a[16];
const int di[] = {1,0,-1,0};
const int dj[] = {0,-1,0,1};
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
  for(int i=0;i<16;i++) cin >> a[i];
  int ans = 0;
  for(int s=0;s<1<<16;s++){
    bool ok = true;
    int sv = -1;
    vector<vector<bool> > use(6,vector<bool>(6));
    for(int j=0;j<16;j++){
      if(s>>j&1){
        sv = j;
        int jh = j/4;
        int jw = j%4;
        jh++; jw++;
        use[jh][jw] = true;
      }
      if(a[j] == 1 && !(s>>j&1)){
        ok = false;
        break;
      }
    }
    if(!ok) continue;
    if(sv == -1){
      ans++;
      continue;
    }
    int si = sv/4+1;
    int sj = sv%4+1;
    sv = si*6+sj;
    vector<vector<bool> > seen(6,vector<bool>(6));
    auto dfs = [&](auto dfs,int v)->void{
      seen[v/6][v%6] = true;
      int i = v/6; int j =v%6;
      for(int d=0;d<4;d++){
        int ni = i+di[d];
        int nj = j+dj[d];
        if(ni < 0 || nj < 0 || ni >= 6 || nj >= 6) continue;
        if(seen[ni][nj]) continue;
        if(!use[ni][nj]) continue;
        dfs(dfs,ni*6+nj);
      }
    };
    dfs(dfs,sv);
    for(int i=0;i<6;i++){
      if(!ok) break;
      for(int j=0;j<6;j++){
        if(use[i][j] && !seen[i][j]) {
          ok = false;
          break;
        }
      }
    }
    if(!ok) continue;
    UnionFind uf(36);
    for(int i=0;i<6;i++){
      for(int j=0;j<6;j++){
        if(i+1 < 6 && use[i][j] && use[i+1][j]) uf.merge(i*6+j,(i+1)*6+j);
        if(j+1 < 6 && use[i][j] && use[i][j+1]) uf.merge(i*6+j,i*6+j+1);
        if(i+1 < 6 && !use[i][j] && !use[i+1][j]) uf.merge(i*6+j,(i+1)*6+j);
        if(j+1 < 6 && !use[i][j] && !use[i][j+1]) uf.merge(i*6+j,i*6+j+1);
      }
    }
    set<int> st;
    for(int i=0;i<36;i++) st.insert(uf.root(i));
    if(st.size() == 2) ans++;
  }
  cout << ans << endl;
  return 0;
}

