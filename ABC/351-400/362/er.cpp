#include <iostream>
#include <atcoder/modint>
#include <vector>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using mint = modint998244353;

mint dp[81][81][81];

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n)rep(j,n)rep(k,n) dp[i][j][k] = 0;
  rep(i,n){
    for(int j=i+1;j<n;++j){
      for(int k=j+1;k<n;k++){
        for(int l=1;l<n;l++){
          dp[i][j][l] += dp[j][k][l-1];
        }
      }
    }
  }
  vector<mint> ans(n);
  ans[0] = mint(n);
  rep(i,n){
    for(int j=i+1;j<n;j++){
      for(int l=1;l<=n;l++){
        ans[l] += dp[i][j][l];
      }
    }
  }
  rep(i,n) cout << ans[i].val() << ' '; cout << endl;
  return 0;
}