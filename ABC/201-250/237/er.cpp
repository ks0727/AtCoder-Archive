#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  vector<vector<P> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(h[a] > h[b]) swap(a,b);
    g[a].emplace_back(2*(h[b]-h[a]),b);
    g[b].emplace_back(h[a]-h[b],a);
  }
  const ll INF = 1e18;
  vector<ll> dist(n,INF);
  dist[0] = 0;
  priority_queue<P,vector<P>,greater<P> > q;
  q.emplace(0,0);
  while(!q.empty())
  {
    auto[c,v] = q.top(); q.pop();
    if(c > dist[v]) continue;
    for(auto [cc,u] : g[v])
    {
      if(dist[u] > c+cc){
        dist[u] = c+cc;
        q.emplace(c+cc,u);
      }
    }
  }
  ll ans = INF;
  for(int i=0;i<n;i++) ans = min(ans,dist[i]);
  cout << -ans << endl;
  return 0;
}

