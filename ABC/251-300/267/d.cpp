#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    const ll INF = 1e18;
    vector dp(n+1,vector<ll>(m+1,-INF));
    rep(i,n+1){
        dp[i][0] = 0;
    }
    for(int i=1;i<=(n);i++){
        for(int j=1;j<=(m);j++){
            if(j <= i) dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]+(ll)j*a[i-1]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}