#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    vector<int> c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    vector<vector<int> > g(n);
    for(int i=0;i<m;i++)
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector cnt(n,vector<int>(n,-1));
    cnt[0][n-1] = 0;
    queue<pair<int,int> > q;
    q.emplace(0,n-1);
    while(!q.empty())
    {
      auto [a,b] = q.front(); q.pop();
      for(int u : g[a]){
        for(int v : g[b]){
          if(c[u] == c[v]) continue;
          if(cnt[u][v] != -1) continue;
          cnt[u][v] = cnt[a][b]+1;
          q.emplace(u,v);
        }
      }
    }
    cout << cnt[n-1][0] << endl;
  }
}
