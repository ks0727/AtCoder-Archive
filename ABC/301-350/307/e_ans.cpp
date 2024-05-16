#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<mint> > dp(n,vector<mint>(2));
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][1]; //0を塗る場合はそのまま引き継ぐ
        dp[i][1] = dp[i-1][0]*(m-1); //0以外を塗る場合はm-1色で塗ることができる
        dp[i][1] += dp[i-1][1]*(m-2); //1からきたら、0と同じ色以外のm-2色で塗ることができる
    }
    
    mint ans = dp[n-1][1]*m;
    cout << ans.val() << endl;
    return 0;
}