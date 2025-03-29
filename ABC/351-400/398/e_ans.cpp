#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  vector<pair<int,int> > es;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    es.emplace_back(a,b);
  }
  vector<vector<int> > vs(2);
  auto dfs = [&](auto dfs, int v, int c, int p=-1)->void{
    vs[c].push_back(v);
    for(int u : g[v]){
      if(u == p) continue;
      dfs(dfs,u,c^1,v);
    }
  };
  dfs(dfs, 0,0);
  set<pair<int,int> > st;
  for(int a : vs[0]) for(int b: vs[1]){
    st.emplace(min(a,b),max(a,b));
  }
  for(auto e : es) st.erase(e);
  bool me = false;
  if(st.size()%2) me = true;
  if(me) cout << "First" << endl;
  else cout << "Second" << endl;
  while(1){
    if(me){
      auto it = st.begin();
      auto [a,b] = *it;
      st.erase(it);
      cout << a+1 << " " << b+1 << endl;
    }else{
      int a,b;
      cin >> a >> b;
      if(a == -1 && b == -1) break;
      a--; b--;
      st.erase(make_pair(a,b));
    }
    me = !me;
  }
  return 0;
}

