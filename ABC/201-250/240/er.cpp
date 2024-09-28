#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<pair<int,int> > ans(n);
  for(int i=0;i<n;i++)
  {
    ans[i].first = 1001001001;
    ans[i].second = -1;
  }
  int cnt = 1;
  auto dfs = [&](auto dfs, int v,int p=-1)->pair<int,int>{
    int left = ans[v].first;
    int right = ans[v].second;
    for(int u : g[v])
    {
      if(u == p) continue;
      pair<int,int> ps = dfs(dfs,u,v);
      left = min(left,ps.first);
      right = max(right,ps.second);
    }
    if(left == 1001001001 && right == -1){
      left = right = cnt;
      ans[v].first = ans[v].second = cnt;
      cnt++;
    }
    return ans[v] = make_pair(left,right);
  };
  dfs(dfs,0);
  for(int i=0;i<n;i++) cout << ans[i].first << ' ' << ans[i].second << endl;
  return 0;
}
