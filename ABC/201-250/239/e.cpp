#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> x(n);
  for(int i=0;i<n;i++) cin >> x[i];
  vector<vector<int> > g(n);
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<vector<int> > dp(n,vector<int>(20,-1));
  for(int i=0;i<n;i++) dp[i][0] = x[i];
  auto dfs = [&](auto dfs,int v, int p=-1)->vector<int>{
    vector<int> a = dp[v];
    for(int u:g[v])
     {
       if(u == p) continue;
       vector<int> b = dfs(dfs,u,v);
       vector<int> c;
       for(int i=0;i<20;i++)
       {
         c.push_back(a[i]);
         c.push_back(b[i]);
       }
       sort(c.rbegin(),c.rend());
       for(int i=0;i<20;i++) c.pop_back();
       a = c;
     }
     return dp[v] = a;
   };
  dfs(dfs,0);
  while(q--)
  {
    int v,k;
    cin >> v >> k;
    v--; k--;
    cout << dp[v][k] << endl;
  }
  return 0;
}

