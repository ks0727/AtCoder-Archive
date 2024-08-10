#include <iostream>
#include <queue>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;

struct Edge{
  int to; ll cost;
  Edge(int to, ll cost): to(to),cost(cost){}
};

int main(){
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  s--; t--;
  const ll INF = 1e18;
  vector<ll> dy(n,INF),ds(n,INF);
  vector<vector<Edge> > gy(n),gs(n);
  rep(i,m){
    int v,u; ll a,b;
    cin >> v >> u >> a >> b;
    v--;u--;
    gy[v].emplace_back(u,a);
    gy[u].emplace_back(v,a);
    gs[v].emplace_back(u,b);
    gs[u].emplace_back(v,b);
  }
  auto f = [&](vector<vector<Edge> > g, vector<ll> &dist, int start){
    priority_queue<P,vector<P>, greater<P> > q;
    dist[start] = 0;
    q.emplace(0,start);
    while (!q.empty())
    {
      auto [c,v] = q.top(); q.pop();
      if(c > dist[v]) continue;
      for(auto e : g[v]){
        if(dist[v] + e.cost < dist[e.to]){
          dist[e.to] = dist[v] + e.cost;
          q.emplace(dist[e.to],e.to);
        }
      }
    }
  };
  f(gy,dy,s);
  f(gs,ds,t);
  vector<ll> dist(n,INF);
  rep(i,n) dist[i] = dy[i]+ds[i];
  vector<ll> su(n+1);
  su[n] = INF;
  for(int i=n-1;i>=0;i--) su[i] = min(su[i+1],dist[i]);
  vector<ll> ans(n,1e15);
  rep(i,n) cout << ans[i] - su[i] << endl;
  return 0;
}
