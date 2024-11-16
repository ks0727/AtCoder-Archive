#include <iostream>
#include<vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct Edge{
  int to,id;
  Edge(){}
  Edge(int to,int id):to(to),id(id){}
};
int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(m);
  for(int i=0;i<m;i++) cin >> a[i],a[i]--;
  vector<vector<Edge> > g(n);
  for(int i=0;i<n-1;i++){
    int v,u;
    cin >> v >> u;
    v--; u--;
    g[u].emplace_back(u,i);
    g[v].emplace_back(u,i);
  }
  vector<int> c(n-1);
  for(int i=0;i<m-1;i++){
    int sv = a[i]; int u = a[i+1];
    auto dfs = [&](auto dfs, int v, int p=-1)->bool{
      if(v == u) return true;
      for(auto e : g[v]){
        if(e.to == p) continue;
        if(dfs(dfs,e.to,v)){
          c[e.id]++;
          return true;
        }
      }
      return false;
    };
    dfs(dfs,sv);
  }
  int s = 0;
  for(int i=0;i<n-1;i++) s += c[i];
  int r2 = k+s;
  if(r2 < 0 || r2 > s*2 || r2%2 == 1){
    cout << 0 << endl;
    return 0;
  }
  int r = r2/2;
  vector<mint> dp(r+1);
  dp[0] = 1;
  for(int x : c){
    for(int i=r-x;i>=0;i--){
      dp[i+x] += dp[i];
    }
  }
  cout << dp[r].val() << endl;
  return 0;
}

