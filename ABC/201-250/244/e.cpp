#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

mint dp[2005][2005][2];

int main(){
  int n,m,k,s,t,x;
  cin >> n >> m >> k >> s >> t >> x;
  s--; t--; x--;
  vector<vector<int> > g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dp[0][s][0] = 1;
  for(int i=0;i<k;i++){
    for(int j=0;j<n;j++){
      for(int nj : g[j]){
        if(nj == x){
           dp[i+1][nj][1] += dp[i][j][0];
           dp[i+1][nj][0] += dp[i][j][1];
         }else{
           dp[i+1][nj][1] += dp[i][j][1];
           dp[i+1][nj][0] += dp[i][j][0];
        }
     }
   }
 }
 mint ans = dp[k][t][0];
  cout << ans.val() << endl;
  return 0;
}

