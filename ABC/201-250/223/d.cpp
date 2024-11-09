#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  vector<int> dim(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    dim[b]++;
  }
  priority_queue<int,vector<int>,greater<int> > q;
  vector<int> ans;
  for(int i=0;i<n;i++) if(dim[i] == 0) q.push(i);
  while(!q.empty()){
    int v = q.top(); q.pop();
    ans.push_back(v);
    for(int u : g[v]){
      dim[u]--;
      if(dim[u] == 0){
        q.push(u);
      }
    }
  }
  if(ans.size() != n) cout << -1 << endl;
  else{
    for(int i=0;i<n;i++) cout << ans[i]+1 << ' '; cout << endl;
  }
  return 0;
}

