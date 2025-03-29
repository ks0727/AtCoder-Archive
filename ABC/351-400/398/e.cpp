#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
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
  const int INF = 1e9;
  vector<vector<int> > dist(n,vector<int>(n,INF));
  for(int sv=0;sv<n;sv++){
    dist[sv][sv] = 0;
    auto dfs = [&](auto dfs, int v, int p=-1)->void{
      if(p != -1) dist[sv][v] = dist[sv][p]+1;
      for(int u : g[v]){
        if(u == p) continue;
        dfs(dfs, u,v);
      }
    };
    dfs(dfs,sv);
  }
  set<pair<int,int> > st;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(dist[i][j]%2 == 1 && dist[j][i]%2 == 1 && dist[i][j] >= 3 && dist[j][i] >= 3){
        st.emplace(i,j);
      }
    }
  }
  cout << st.size() << endl;
  if(st.size()%2 == 0) cout << "Second" << endl;
  else cout << "First" << endl;
  bool mine = st.size()%2 == 1;
  while(st.size()){
    if(mine){
      auto [i,j] = *st.begin();
      cout << i+1 << ' ' << j+1 << endl;
      st.erase(st.begin());
      mine = false;
    }else{
      int i,j;
      cin >> i >> j;
      if(i == -1 && j == -1) return 0;
      i--; j--;
      if(st.count(make_pair(i,j))) st.erase(make_pair(i,j));
      else st.erase(make_pair(j,i));
      mine = true;
    }
  }
  return 0;
}

