#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<mint> > dp(n+1,vector<mint>(n+1));
    dp[0][0] = 1;
    for(int i=1;i<=(n);i++){
        if(s[i-1] == '('){
            dp[i][0] = 0;
            for(int j=1;j<=n;j++) dp[i][j] = dp[i-1][j-1];
        }
        else if(s[i-1] == ')'){
            rep(j,n) dp[i][j] = dp[i-1][j+1];
            dp[i][n] = 0;
        }else{
            for(int j = 1;j<(n);j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
            dp[i][0] = dp[i-1][1];
            dp[i][n] = dp[i-1][n-1];
        }
    }
    cout << dp[n][0].val() << endl;
    return 0;
}