#include<map>
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
  int n,m;
  cin >> n>> m;
  const ll INF = 1e18;
  vector dp(n+1,vector<ll>(n+1,-INF));
  vector<ll> x(n);
  for(int i=0;i<n;i++) cin >> x[i];
  vector<ll> bonus(n+1);
  for(int i=0;i<m;i++){
    int c; ll y;
    cin >> c >> y;
    bonus[c] = y;
  }
  dp[0][0] = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=n;j++){
      if(j>=1 && dp[i][j-1] != -INF) dp[i+1][j] = max(dp[i+1][j],dp[i][j-1]+x[i] + bonus[j]);
      dp[i+1][0] = max(dp[i][j],dp[i+1][0]);
    }
  }
  ll ans = 0;
  for(int i=0;i<=n;i++) ans = max(ans,dp[n][i]);
  cout << ans << endl;
}   
  

