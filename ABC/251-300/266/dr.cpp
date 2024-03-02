#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> t(n),x(n),a(n);
    rep(i,n) cin >> t[i] >> x[i] >> a[i];
    const ll INF = 1e18;
    const int M = 100005;
    vector dp(M,vector<ll>(5,-INF));
    dp[0][0] = 0;
    int now = 0;
    rep(i,M-1){
        rep(j,5){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j > 0) dp[i+1][j] = max(dp[i+1][j],dp[i][j-1]);
            if(j < 4) dp[i+1][j] = max(dp[i+1][j],dp[i][j+1]);
            if(now < n && i+1 == t[now] && j == x[now]){
                dp[i+1][j] += a[now];
                now++;
            }
        }
    }
    ll ans = -1;
    rep(j,4){
        ans = max(ans,dp[M-1][j]);
    }
    cout << ans << endl;
    return 0;
}