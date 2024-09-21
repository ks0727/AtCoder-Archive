#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for(int i=0;i<n;i++){
    int c;
    cin >> c;
    for(int j=0;j<c;j++){
      int p;
      cin >> p;
      p--;
      g[i].push_back(p);
    }
  }
  set<int> st;
  vector<int> ans;
  auto dfs = [&](auto dfs, int v)->void{
      for(int u : g[v]){
        if(!st.count(u)){
          dfs(dfs,u);
        }
      }
      if(!st.count(v)){
        ans.push_back(v);
        st.insert(v);
      }
      return;
    };
    dfs(dfs,0);
    ans.pop_back();
  for(int x : ans) cout << x+1 << ' ';
   cout << endl;
  return 0;
}

