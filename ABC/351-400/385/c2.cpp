#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    const int INF = 1001001001;
    vector<vector<int> > dp(n,vector<int>(n));
    rep(i,n)rep(j,n) dp[i][j] = 1;
    rep(i,n){
        rep(j,n){
            if(i > j) continue;
            int d = j - i;
            int k = j+d;
            if(k >= n) continue;
            if(h[k] == h[j]){
                dp[j][k] = max(dp[j][k],dp[i][j]+1);
            }else{
                dp[j][k] = max(dp[j][k],dp[i][j]);
            }
        }
    }
    int ans = 0;
    rep(i,n)rep(j,n) ans = max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}