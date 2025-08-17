#include <iostream>
#include<vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ull = unsigned long long;

void solve(){
  ull n; int k;
  cin >> n >> k;
  const int m = 60;
  mint dp[m+1][60][2];
  for(int i=0;i<m+1;i++)for(int j=0;j<=k;j++)for(int l=0;l<2;l++) dp[i][j][l] = 0;
  vector<mint> ts(k+1);
  mint now = 1;
  for(int i=0;i<=m;i++){
    ts[i] = now;
    now *= 2;
  }
  dp[0][0][0] = 1;
  for(int i=0;i<m;i++){
    for(int j=0;j<60;j++){
      //lが0->以下が確定していない
      //lが1->以下が確定している
        if(~(n>>(m-i)&1)) continue; //以下が確定していない時にnが0であったら確定で0
        dp[i+1][j][1] += dp[i][j][0];
        dp[i+1][j+1][0] += dp[i][j][0]+ts[m-i];
        dp[i+1][j+1][1] += dp[i][j][1]+ts[m-i];
        dp[i+1][j][1] += dp[i][j][1];
      }
  }
  cout << dp[m][k][1].val() << endl;
}


int main(){
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}

