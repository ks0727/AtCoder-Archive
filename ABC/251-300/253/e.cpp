#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using mint = modint998244353;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    vector dp(n+1,vector<mint>(m+1));
    for(int j = 1; j <= m ;j++) dp[0][j] = 1;
    rep(i,n-1){
        vector<mint> s(m+1); // 1 ~ m までの累積和　s[i] := iまでの累積和
        rep(j,m) s[j+1] = s[j] + dp[i][j+1];
        for(int j=1;j<=m;j++){
            if(k == 0) dp[i+1][j] += s[m];
            else{
            if(j-k>=1) dp[i+1][j] += s[j-k];
            if(j+k-1 <= m) dp[i+1][j] += s[m] - s[j+k-1];
            }
        }
    }
    mint ans = 0;
    for(int j = 1; j<=m;j++) ans += dp[n-1][j];
    cout << ans.val() << endl;
    return 0;
}