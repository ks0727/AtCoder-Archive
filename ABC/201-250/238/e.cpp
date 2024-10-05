#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
  int n,Q;
  cin >> n >> Q;
  vector<vector<int> > g(n+1);
  for(int i=0;i<Q;i++)
  {
    int a,b;
    cin >> a >> b;
    a--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int s = 0;
  queue<int> q;
  vector<bool> vis(n+1);
  q.push(0);
  while(!q.empty())
   {
     int v = q.front(); q.pop();
     vis[v] = true;
     for(int u : g[v])
     {
        if(vis[u]) continue;
        q.push(u);
     }
   }
  if(vis[n]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

