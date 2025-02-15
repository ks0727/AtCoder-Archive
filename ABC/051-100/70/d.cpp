#include <iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<long long,int>;
int main(){
  int n;
  cin >> n;
  vector<vector<P> > g(n);
  for(int i=0;i<n-1;i++){
    int a,b; long long c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(c,b);
    g[b].emplace_back(c,a);
  }
  int Q,k;
  cin >> Q >> k;
  k--;
  const long long INF = 1e18;
  vector<long long> dist(n,INF);
  dist[k] = 0;
  queue<int> q;
  q.push(k);
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(auto [c,u] : g[v]){
      if(u == v) continue;
      if(dist[u] != INF) continue;
      dist[u] = dist[v] + c;
      q.push(u);
    }
  }
  while(Q--){
    int x,y;
    cin >> x >> y;
    x--; y--;
    long long ans = dist[x] + dist[y];
    cout << ans << '\n';
  }
  return 0;
}

