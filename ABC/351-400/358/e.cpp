#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

mint dp[1001][27][1001];

int main(){
    int k;
    cin >> k;
    vector<int> c(26);
    rep(i,26) cin >> c[i];
    rep(i,k){
        rep(j,26){
            rep(l,k){
                dp[i][j+1][l] = dp[i][j][l]+1;
            }
        }
    }
    mint ans = 0;
    rep(i,k){
        ans += dp[i][26][i];
    }
    cout << ans.val() << endl;
    return 0;
}