#include <iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;
using T = tuple<long long,int,int>;
int main(){
  int n,m;
  cin >> n>> m;
  vector<vector<T> > g(n);
  for(int i=0;i<m;i++){
    int a,b; long long c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(c,b,i);
    g[b].emplace_back(c,a,i);
  }
  priority_queue<T,vector<T>,greater<T> > q;
  q.emplace(0,0,-1);
  const long long INF = 1e18;
  vector<long long> dist(n,INF);
  vector<int> ans(n,-1);
  dist[0] = 0;
  while(!q.empty()){
    auto [c,v,id] = q.top(); q.pop();
    if(c != dist[v]) continue; 
    for(auto nxt : g[v]){
      auto [nc,u,nid] = nxt;
      if(nc + dist[v] < dist[u]){
        dist[u] = nc + dist[v];
        ans[u] = nid;
        q.emplace(dist[u],u,nid);
      }
    }
  }
  for(int i=0;i<n;i++) if(ans[i] != -1) cout << ans[i]+1 << ' '; cout << endl;
}


      


