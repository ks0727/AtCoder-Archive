#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  priority_queue<P,vector<P>,greater<P> > pq;
  pq.emplace(0,0);
  const int INF = 1001001001;
  vector<int> dist(n,INF);
  while(!pq.empty()){
    auto [c,v] = pq.top(); pq.pop();
    if(c > dist[v]) continue;
    for(int u : g[v]){
      int nc = max(h[u]-h[v],0);
      if(c + nc < dist[u]){
        dist[u] = c+nc;
        pq.emplace(dist[u],u);
      }
    }
  }
  vector<int> ans(n);
  ans[0] = 0;
  for(int i=0;i<n;i++){
    ans[i] = h[0]-h[i]-dist[i];
  }
  int fans = 0;
  for(int i=0;i<n;i++) fans = max(fans,ans[i]);
  cout << fans << endl;
}
