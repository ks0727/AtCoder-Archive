#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    mint ans = 0;
    for(int i=1;i<=(n);i++){
        mint dp[n+1][n+1][n+1];
        rep(j,n+1)rep(k,i+1)rep(l,i+1) dp[j][k][l] = 0;
        dp[0][0][0] = 1;
        rep(j,n){
            rep(k,i+1){
                rep(l,i){
                    dp[j+1][k][l]+=dp[j][k][l];
                    if(k != i) dp[j+1][k+1][(l+a[j])%i] += dp[j][k][l];  
                }
            }
        }
        ans += dp[n][i][0];
    }
    cout << ans.val() << endl;
    return 0;
}