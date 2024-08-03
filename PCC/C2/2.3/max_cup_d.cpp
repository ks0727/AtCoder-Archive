#include <iostream>
using namespace std;
using ll = long long;
int a[10000];
ll dp[10001][1001];
int main(){
  int n,m,l,x;
  cin >> n >> m >> l >> x;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n+1;i++)for(int j=0;j<m;j++) dp[i][j] = 1e18;
  dp[0][0] = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(j+a[i] >= m) dp[i+1][(j+a[i])%m] = min(dp[i][j]+(j+a[i])/m,dp[i+1][(j+a[i])%m]);
      else dp[i+1][j+a[i]] = min(dp[i][j],dp[i+1][j+a[i]]);
      dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
    }
  }
  if(dp[n][l] < x) cout << "Yes" << endl;
  else cout << "No" << endl; 
    
  return 0;
}

