#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge{
  int to,w;
};

int main(){
  int n,m;
  cin >> n >> m;
  int W = 1<<10;
  vector<vector<Edge> > g(n);
  for(int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    a--; b--;
    g[a].emplace_back(b,w);
  }
  vector<bool> visited(n*W);
  queue<int> q;
  auto push = [&](int v, int x){
    int vid = v*W _ x;
    if(visited[vid]) return;
    visited[vid] =  true;
    q.push(vid);
  };
  push(0,0);
  while(q.size()){
    int vid = q.front(); q.pop();
    int v = vid/W; int x = vid%W;
    for(auto e : g[v]) push(e.to,x^e.w);
  }
  for(int x=0;x<W;x++){
    if(visited[(n-1)*W+x]){
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

