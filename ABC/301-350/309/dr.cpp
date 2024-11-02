#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  int n1,n2,m;
  cin >> n1 >> n2 >> m;
  int n = n1 + n2;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >>  a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> dist(n,-1);
  dist[0] = dist[n-1] = 0;
  for(int i=0;i<2;i++){
    int s = -1;
    if(i == 0) s = 0;
    else s = n-1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      int v = q.front(); q.pop();
      for(int u : g[v]){
        if(dist[u] != -1) continue;
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
 int ans = 0;
 int mx1 = 0;
 for(int i=0;i<n1;i++) mx1 = max(mx1,dist[i]);
  ans += mx1;
  int mx2 = 0;
  for(int i=0;i<n2;i++) mx2 = max(mx2,dist[i+n1]);
  ans += mx2;
  ans++;
  cout << ans << endl;
  return 0;
}

