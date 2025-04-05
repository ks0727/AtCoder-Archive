#include <iostream>
#include<vector>
#include<queue>
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
  vector<int> svs;
  for(int i=0;i<n;i++){
    if(dim[i] == 0) svs.push_back(i);
  }
  for(int sv : svs){
    queue<int> q;  
    q.push(sv);
    while(!q.empty()){
      int v = q.front(); q.pop();
      for(int u : g[v]){
        dim[u]--;
        if(dim[u] == 0) q.push(u);
      }
    }
  }
  for(int sv=0;sv<n;sv++){
    if(dim[sv] ==0) continue;
    int v = sv;
    vector<int> cycle;
    do{
      v = g[v];
      cycle.push_back(v);
    }while(v != sv);

  return 0;
}

