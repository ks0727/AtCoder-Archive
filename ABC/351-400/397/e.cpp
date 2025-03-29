#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<vector<int> > g(n*k);
  for(int i=0;i<n*k-1;i++){
    int a,b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bool ok = true;
  auto dfs = [&](auto dfs, int v, int p=-1)->int{
    int now = 1;
    for(int u : g[v]){
      if(u == p) continue;
      int num = dfs(dfs,u,v);
      num %= k;
      now += num;
    }
    if(now > k) ok = false;
    return now;
  };
  dfs(dfs,0);
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

