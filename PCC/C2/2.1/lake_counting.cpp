#include <iostream>
#include <vector>
using namespace std;
const int di[] = {1,1,1,0,0,-1,-1,-1};
const int dj[] = {1,0,-1,1,-1,1,0,-1};
using P = pair<int,int>;

int main(){
   int n,m;
   cin >> n >> m;
   vector<string> g(n);
   for(int i=0;i<(n);i++) cin >> g[i];
   vector<vector<bool> > seen(n,vector<bool>(m));
   int ans = 0;
   auto dfs = [&](auto dfs,P pos)->void{
     auto [i,j] = pos;
     seen[i][j] = true;
     for(int v = 0;v<(8);v++){
        int ni = i + di[v];
        int nj = j + dj[v];
        if(ni < 0 || nj < 0 || ni >= n || nj >=m) continue;
        if(g[ni][nj] != 'W') continue;
        if(seen[ni][nj]) continue;
        dfs(dfs,P(ni,nj));
      }
   };
  for(int i=0;i<(n);i++){
      for(int j=0;j<(m);j++){
          if(g[i][j] == '*' || seen[i][j]) continue;
          dfs(dfs,P(i,j));
          ans++;
        }
    }

  cout << ans << endl;
  return 0;
}
