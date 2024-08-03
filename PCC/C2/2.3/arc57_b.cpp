#include <iostream>
using namespace std;
using ll = long long;
ll a[2000];
ll dp[2001][2001];

int main(){
  int n; ll k;
  cin >> n >> k;
  const ll INF = 1e18;
  for(int i=0;i<n;++i) cin >> a[i];
  for(int i=0;i<n+1;i++)for(int j=0;j<n+1;j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for(int i=0;i<n;++i){
    for(int j=0;j<=i;j++){
      dp[i+1][j+1] = min(dp[i][j]+a[i],dp[i+1][j+1]);
      dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
    }
  }
  for(int i=0;i<n+1;i++){
    for(int j=0;j<=i;j++){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  int ans = 0;
  for(int j=0;j<n+1;j++) if(dp[n][j] <= k) ans = max(j,ans);
  cout << ans << endl;
  return 0;
}

