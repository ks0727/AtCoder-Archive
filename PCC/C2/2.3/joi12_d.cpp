#include <iostream>
#include <vector>
using namespace std;

int main(){
  int d,n;
  cin >> d >> n;
  vector<int> t(d);
  for(int i=0;i<d;++i) cin >> t[i];
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;++i) cin >> a[i] >> b[i] >> c[i];
  const int INF = 1e9;
  vector<vector<int> > dp(d+1,vector<int>(n+1,-INF));
  for(int i=0;i<n;++i) dp[0][i] = 0;
  for(int i=0;i<d;++i){
    for(int j=0;j<n;++j){
      for(int k=0;k<n;++k){
        if(a[k]<=t[i] && t[i]<=b[k]){
          if(i == 0) dp[i+1][k] = max(dp[i][j],dp[i+1][k]);
          else dp[i+1][k] = max(dp[i][j]+abs(c[j]-c[k]),dp[i+1][k]);
        }
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;++i) ans = max(ans,dp[d][i]);
  cout << ans << endl;
  return 0;
}

