#include <iostream>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
mint dp[1<<20][9];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<9;i++) dp[0][i] = 1;
  for(int i=0;i<n;i++){
    for(int j=0;j<9;j++){
      if(j==0) dp[i+1][j] = dp[i][1]+dp[i][0];
      else if(j==8) dp[i+1][j] = dp[i][7]+dp[i][8];
      else dp[i+1][j] = dp[i][j-1]+dp[i][j+1]+dp[i][j];
    }
  }
  mint ans = 0;
  for(int i=0;i<9;i++) ans += dp[n-1][i];
  cout << ans.val() << endl;
  return 0;
}

