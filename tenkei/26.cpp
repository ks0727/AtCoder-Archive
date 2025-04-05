#include <iostream>
#include<vector>
#include<cassert>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> colors(n,-1);
  auto dfs = [&](auto dfs ,int v, int c, int p=-1)->void{
    colors[v] = c;
    for(int u : g[v]){
      if(u == p) continue;
      if(colors[u] != -1) continue;
      assert(colors[u] != c); 
      dfs(dfs,u,c^1,v);
    }
  };
  dfs(dfs,0,0);
  int zero = 0;
  for(int i=0;i<n;i++) if(colors[i] == 0) zero++;
  if(zero > n/2){
    int cnt = 0;
    for(int i=0;i<n;i++)if(colors[i] == 0) {
      cout << i+1 << ' ';
      cnt++;
      if(cnt == n/2) break;
    }
  }else{
    int cnt = 0;
    for(int i=0;i<n;i++)if(colors[i] == 1){
      cout << i+1 << ' ';
      cnt++;
      if(cnt == n/2) break;
    }
  }
  cout << endl;
  return 0;
}

