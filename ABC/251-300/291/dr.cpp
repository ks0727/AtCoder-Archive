#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<mint> > dp(n,vector<mint>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i=1;i<n;++i){
        if(a[i] != a[i-1]) dp[i][0] += dp[i-1][0];
        if(a[i] != b[i-1]) dp[i][0] += dp[i-1][1];
        if(b[i] != a[i-1]) dp[i][1] += dp[i-1][0];
        if(b[i] != b[i-1]) dp[i][1] += dp[i-1][1];
    }
    mint ans = dp[n-1][0] + dp[n-1][1];
    cout << ans.val() << endl;
    return 0;
}