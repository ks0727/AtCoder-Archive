#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<int> q;
  vector<int> from(n,-1);
  from[0] = 1001001001;
  q.push(0);
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u : g[v]){
      if(from[u] != -1) continue;
      from[u] = v;
      q.push(u);
    }
  }
  for(int i=0;i<n;i++){
    if(from[i] == -1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for(int i=1;i<n;i++){
    cout << from[i] + 1 << endl;
  }
  return 0;
}

