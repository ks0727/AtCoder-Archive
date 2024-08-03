#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
  int N; ll W;
  cin >> N >> W;
  vector<ll> v(N),w(N);
  rep(i,N) cin >> v[i] >> w[i];
  if(N <= 30){
    vector dp(N+1,vector<ll>(W+1));
    rep(i,N){
      rep(j,W+1){
        dp[i+1][j] = dp[i][j];
        if(j-w[i] >=0) dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
      }
    }
    cout << dp[N][W] << endl;
    return 0;
  }else{
    bool vuse = true;
    const int m = 2<<17;
    rep(i,N) if(v[i] > 1000) vuse = false;
    if(vuse){
      const ll INF = 1e18;
      vector dp(N+1,vector<ll>(m+1,INF));
      dp[0][0] = 0;
      rep(i,N){
        rep(j,m+1){
          dp[i+1][j] = dp[i][j];
          if(j-w[i] >=0) dp[i+1][j] = min(dp[i][j-v[i]]+w[i],dp[i][j]);
        }
      }
      ll ans = INF;
      rep(i,N+1){
        rep(j,m+1){
          if(dp[i][j] <= W) ans = min(ans,(ll)j);
        }
      }
      cout << ans << endl;
      return 0;
    }else{
      const ll INF = 1e18;
      vector dp(N+1,vector<ll>(m+1,-INF));
      dp[0][0] = 0;
      rep(i,N){
        rep(j,m+1){
          if(j > W) continue;
          dp[i+1][j] = dp[i][j];
          if(j-w[i] >= 0) dp[i+1][j] = max(dp[i][j-w[i]]+v[i],dp[i][j]);
        }
      }
      ll ans = 0;
      rep(i,N+1){
        rep(j,m+1){
          if(j > W) continue;
          ans = max(ans,dp[i][j]);
        }
      } 
      cout << ans << endl;
      return 0;
    }
  }
}
