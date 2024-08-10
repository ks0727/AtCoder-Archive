#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll dp[81][81][10001];

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    const ll INF = 1e18;
    rep(i,n+1)rep(j,n+1)rep(k,x+1) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        rep(j,n){
            rep(k,x+1){
                dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                if(k-a >= 0) dp[i+1][j+1][k] = min(dp[i][j][k-a] + b,dp[i+1][j+1][k]); //食べる時
            }
        }
    }
    int ans = 0;
    rep(j,n+1)rep(k,x+1){
        if(dp[n][j][k] <= y) ans = max(j,ans);
    }
    cout << min(ans+1,n) << endl;
    return 0;
}
