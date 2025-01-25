#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<vector<pair<long long,int>> > g(n);
  for(int i=0;i<m;i++){
    int u,v; long long b;
    cin >> u >> v >> b;
    u--; v--;
    g[u].emplace_back(b,v); 
    g[v].emplace_back(b,u); 
  }
  const long long INF = 1e18;
  vector<long long> dist(n,INF);
  dist[0] = a[0];
  priority_queue<pair<long long,int>,vector<pair<long long,int> > , greater<pair<long long,int>> > q;
  q.emplace(a[0],0);
  while(!q.empty()){
    auto [cost,v] = q.top(); q.pop();
    if(cost != dist[v]) continue;
    for(auto [nc,u] : g[v]){
      if(cost + nc + a[u] < dist[u]){
        dist[u] = cost + nc + a[u];
        q.emplace(dist[u],u);
      }
    }
  }
  for(int i=0;i<n-1;i++) cout << dist[i+1] << ' '; cout << endl;
}




  
