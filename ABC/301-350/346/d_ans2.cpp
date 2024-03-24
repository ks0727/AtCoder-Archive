#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

void chmin(ll &a,ll b){a = min(a,b);}
ll dp[200050][2][2];

int main(){
    int n; string s;
    cin >> n >> s;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    const ll INF = 1e18;
    rep(i,n+1)rep(j,2)rep(k,2) dp[i][j][k] = INF;
    rep(j,2){
        int cost = 0;
        if(s[0] != '0'+j) cost = c[0];
        dp[0][j][0] = cost;
    }
    for(int i=1;i<n;i++){
        rep(j,2){
            rep(k,2){
                rep(nj,2){
                    int nk = k;
                    if(j == nj) nk++;
                    if(nk >= 2) continue;
                    int cost = 0;
                    if(s[i] != '0'+nj) cost = c[i];
                    chmin(dp[i+1][nj][nk],dp[i][j][k]+cost);
                }
            }
        }
    }
    ll ans = INF;
    rep(j,2) chmin(ans,dp[n][j][1]);
    cout << ans << endl;
    return 0;
}