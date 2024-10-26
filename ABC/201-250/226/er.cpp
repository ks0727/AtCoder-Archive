#include <iostream>
#include <vector>
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
    g[b].push_back(a);
    dim[a]++;
    dim[b]++;
  }
  vector<bool> seen(n);
  for(int i=0;i<n;i++){
    if(dim[i] == 1){
      auto dfs = [&](auto dfs,int v,int p=-1)->bool{
        for(int u : g[v]){
          if(dfs(dfs,u,v)) return true;
        }
        return false;
      }
  for(int i=0;i<n;i++){

  return 0;
}

