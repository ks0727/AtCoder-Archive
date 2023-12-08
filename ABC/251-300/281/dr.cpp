#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,k,d;
    cin >> n >> k >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    const ll INF = 1e18;
    vector<vector<vector<ll> > > dp(n+1,vector<vector<ll> >(k+1,vector<ll>(d)));
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,k){
            rep(l,d){
                dp[i+1][j+1][(ll)(l+a[i])%d] = max(dp[i+1][j+1][(ll)(l+a[i])%d],dp[i][j][l]+(ll)a[i]);
                dp[i+1][j+1][l] = dp[i][j+1][l];
            }
        }
    }
    cout << dp[n][k][0] << endl;
    return 0;
}