#include <iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using T = tuple<int,int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<T> >g(n);
  for(int i=0;i<m;i++){
    int a,b; int w;
    cin >> a >> b >> w; a--; b--;
    g[a].emplace_back(w,b,i);
    g[b].emplace_back(w,a,i);
  }
  int ans = 1001001001;
  vector<bool> used(m);
  auto dfs = [&](auto dfs, int v, int now)->void{
    if(v == n-1){
      ans = min(ans,now);
    }
    for(auto [c,u,idx] : g[v]){
      if(used[idx]) continue;
      int nc = 0;
      //for(int i=0;i<10;i++)if((now>>i&1) && (c>>i&1)) nc |= 1<<i;
      used[idx] = true;
      dfs(dfs,u,c^now);
      used[idx] = false;
    }
  };
  dfs(dfs,0,0);
  if(ans == 1001001001) ans = -1;
  cout << ans << endl;
  return 0;
}

