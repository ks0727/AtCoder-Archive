#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> t(n);
  vector<vector<int> > a(n);
  for(int i=0;i<n;i++){
    cin >> t[i];
    int k;
    cin >> k;
    a[i].resize(k);
    for(int j=0;j<k;j++) cin >> a[i][j],a[i][j]--;
    sort(a[i].begin(),a[i].end());
  }
  vector<bool> seen(n);
  auto dfs = [&](auto dfs,int v,int p)->long long{
    long long res = t[v];
    for(int u : a[v]){
      if(seen[u]) continue;
      if(u == p) continue;
      res += dfs(dfs,u,v);
    }
    seen[v] = true;
    return res;
  };
  long long ans = dfs(dfs,n-1,-1);
  cout << ans << endl;
  return 0;
}

