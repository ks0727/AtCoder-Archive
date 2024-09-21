#include <iostream>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
const int M = 2501;

mint dp[51][M];

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  dp[0][0] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=k;j++){
      for(int l=1;l<=m;l++){
        if(j-l >= 0) dp[i+1][j] += dp[i][j-l];
      }
    }
  }
  //for(int i=0;i<n+1;i++){
    //for(int j=0;j<=k;j++) cout << dp[i][j].val() << ' ';
    //cout << endl;
  //}
  mint ans = 0;
  for(int i=0;i<=k;i++) ans += dp[n][i];
  cout << ans.val() << endl;
  return 0;
}

