#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n; int p;
    cin >> n >> p;
    vector<vector<mint> > dp(n+2,vector<mint>(n+2));
    dp[0][0] = 1;
    rep(i,n){
        for(int j=0;j<(n);j++){
            if(dp[i][j] == 0) continue;
            mint two = p/100;
            mint one = 1 - p/100;
            dp[i+1][j+2] = dp[i][j]*two;
            dp[i+1][i+1] = dp[i][j]*one;
        }
    }
    mint ans = 0;
    rep(i,n){
        ans += dp[i][n];
        ans += dp[i][n+1];
    }
    cout << ans.val() << endl;
    return 0;
}