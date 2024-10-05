#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  const ll INF = 1e18;
  vector<ll> hap(n,-INF);
  hap[0] = 0;
  queue<P> q;
  q.push(make_pair(0,-1));
  while(!q.empty()){
    auto [v,p] = q.front(); q.pop();
    for(int u : g[v])
    {
      if(u == p) continue;
      if(h[u] > h[v]){
        if(hap[u] < hap[v]-2*(h[u]-h[v])){
          q.push(make_pair(u,v));
          hap[u] = hap[v]-2*(h[u]-h[v]);
        }
      }
      else{
        if(hap[u] < hap[v]+h[v]-h[u]){
          hap[u] = hap[v]+h[v]-h[u];
          q.push(make_pair(u,v));
        }
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<n;i++) ans = max(ans,hap[i]);
  //for(int i=0;i<n;i++) cout << hap[i] << ' '; cout << endl;
  cout << ans << endl;
  return 0;
}

