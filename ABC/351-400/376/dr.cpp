#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  int n,m;
  cin >> n>> m;
  vector<vector<int> > g(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(b==0) g[a].push_back(n);
    else g[a].push_back(b);
  }
  queue<int> q;
  q.push(0);
  const int INF = 1001001001;
  vector<int> dist(n+1,INF);
  dist[0] = 0;
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u : g[v]){
      if(dist[u] != INF) continue;
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
  if(dist[n] == INF) dist[n] = -1;
  cout << dist[n] << endl;
}

      


