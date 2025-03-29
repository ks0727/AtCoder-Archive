#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int nk = n*k;
  vector<vector<int> > g(nk);
  for(int i=0;i<nk-1;i++){
    int a,b;
    cin >> a > .b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bool ok = true;
  auto dfs = [&](auto dfs, int v, int p=-1)->int{
    int res = 1;
    int deg = 0;
    for(int u : g[v]){
      if(u == p) continue;
      int sz = dfs(dfs, u,v);
      if(sz%k != 0) deg++;
      res += sz;
    }
    if(res%k != 0) deg++;
    if(deg > 2) ok = false;
    return res;
  };
  dfs(dfs,0);
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

