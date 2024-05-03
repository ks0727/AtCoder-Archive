#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
void chmax(ll &a , ll b){
    a = max(a,b);
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<int> counter(n+1);
    rep(i,m){
        int c,y;
        cin >> c >> y;
        counter[c] = y;
    }
    const ll INF = 1e18;
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,-INF));
    dp[0][0] = 0;
    ll px = 0;
    rep(i,n){
        for(int j=0;j<(i+1);j++){
            if(dp[i][j]==-INF) continue;
            if(j == 0) dp[i+1][j] = px;
            chmax(dp[i+1][j+1],dp[i][j]+x[i]);
            dp[i+1][j+1] += counter[j+1];
        }
        for(int j=0;j<(i+1);j++) px = max(px,dp[i+1][j+1]);
    }
    ll ans = -1;
    rep(i,n+1) ans = max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}