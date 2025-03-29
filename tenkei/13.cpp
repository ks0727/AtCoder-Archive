#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<long long,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<long long,int> > > g(n);
  for(int i=0;i<m;i++){
    int a,b; long long c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(c,b);
    g[b].emplace_back(c,a);
  }
  const long long INF = 1e18;
  vector<long long> dist(n,INF),dist2(n,INF);
  dist[0] = 0;
  priority_queue<P,vector<P>,greater<P> > q;
  q.emplace(0,0);
  while(!q.empty()){
    auto [c,v] = q.top(); q.pop();
    if(dist[v] != c) continue;
    for(auto [nc,u] : g[v]) {
      if(dist[u] > dist[v] + nc){
        dist[u] = dist[v] + nc;
        q.emplace(dist[u],u);
      }
    }
  }
  dist2[n-1] = 0;
  q.emplace(0,n-1);
  while(!q.empty()){
    auto [c,v] = q.top(); q.pop();
    if(dist2[v] != c) continue;
    for(auto [nc,u] : g[v]) {
      if(dist2[u] > dist2[v] + nc){
        dist2[u] = dist2[v] + nc;
        q.emplace(dist2[u],u);
      }
    }
  }
  for(int i=0;i<n;i++){
    long long now = dist[i] + dist2[i];
    cout << now << endl;
  }
  return 0;
}

