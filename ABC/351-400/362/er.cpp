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
    vector<mint> ans;
    ans.push_back(n);
    for(int l=2;l<=n;l++){
      mint now = 0;
      rep(i,n){
        for(int j=i+1;j<n;++j){
          if(l == 2){
            dp[i][j][l] = 1;
          }
          for(int k=j+1;k<n;k++){
            if(dp[i][j][l] == 0) continue;
            if(a[j]-a[i] == a[k] - a[j]){
              dp[j][k][l+1] += dp[i][j][l];
            }
          }
          now += dp[i][j][l];
        }
      }
      ans.push_back(now);
    }
    rep(i,n) cout << ans[i].val() << ' '; cout << endl;
    return 0;
}