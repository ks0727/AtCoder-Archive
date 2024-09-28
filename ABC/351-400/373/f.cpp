#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,W;
    cin >> n >> W;
    const ll INF = 1e18;
    vector dp(n+5,vector<ll>(W+5));
    //dp[0][0] = 0;
    vector<ll> w(n),v(n);
    rep(i,n) cin >> w[i] >> v[i];
    rep(i,n){
        int cnt = 1;
        rep(j,W+1){
            if(j-w[i] >= 0) dp[i+1][j] = max(dp[i+1][j-w[i]]+v[i]-2*j/w[i]+1,dp[i][j-w[i]]+v[i]-2*j/w[i]+1);
            else  dp[i+1][j] =  dp[i][j];
            cnt++;
        }
    }
    rep(i,n+1){
        rep(j,W+1) cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << dp[n][W] << endl;
    return 0;
}