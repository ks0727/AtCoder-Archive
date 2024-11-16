#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int> > g(n);
  vector<int> dim(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    dim[a]++;
    dim[b]++;
  }
  vector<bool> seen(n);
  long long ans = 0;
  for(int i=0;i<n;i++){
    if(dim[i] != 3) continue;
    if(seen[i])  continue;
    vector<int> three;
    auto dfs = [&](auto dfs,int v,int p=-1)->void{
      three.push_back(v);
      for(int u : g[v]){
        if(u == p) continue;
        if(dim[u] != 3) continue;
        dfs(dfs,u,v);
      }
    };
    dfs(dfs,i);
    set<int> st;
    for(int x : three){
      seen[x] = true;
      for(int u : g[x]){
        if(dim[u] == 2 && !st.count(u)){
          st.insert(u);
        }
      }
    }
    ans += (st.size())*(st.size()-1)/2;
  }
  cout << ans << endl;   
  return 0;
}

