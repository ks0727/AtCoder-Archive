#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n,m;
    cin >> n >> m;
    vector dp(n+5,vector<mint>(2)); 
    dp[0][0] = m;
    dp[0][1] = 0;
    rep(i,n){
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = dp[i][0]*(m-1)+dp[i][1]*(m-2);
    }
    cout << dp[n-1][1].val() << endl;
    return 0;

}