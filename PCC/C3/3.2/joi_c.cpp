#include <iostream>
using namespace std;
using ll = long long;
ll p[1000];
ll dp[1001][5];

int main(){
  int n; ll m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    ll pi; cin >> pi;
    for(int j=0;j<4;j++){
      for(int k=0;j+k<5;k++){
        if(dp[i][j]+(ll)pi*k <= m) dp[i+1][j+k] = max(dp[i+1][j+k],dp[i][j]+pi*k);
      }
    }
  }
  ll ans = 0;
  for(int j=0;j<5;j++) ans = max(ans,dp[n][j]);
  cout << ans << endl;
  return 0;
}

