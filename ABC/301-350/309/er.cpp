#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> p(n-1);
  vector<vector<int> > g(n);
  for(int i=0;i<n-1;i++){
     cin >> p[i];
     p[i]--;
     g[p[i]].push_back(i+1);
  }
  vector<int> covered(n,-1);
  priority_queue<pair<int,int>,vector<pair<int,int> > > q;
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    x--;
    covered[x] = max(y,covered[x]);
    q.emplace(y,x);
  }
  while(!q.empty()){
    auto [d,v] = q.top(); q.pop();
    if(d != covered[v]) continue;
    for(int u : g[v]){
      if(covered[u] >= d-1) continue;
      covered[u] = d-1;
      q.emplace(d-1,u);
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) if(covered[i] >= 0) ans++;
  cout << ans << endl;
}

