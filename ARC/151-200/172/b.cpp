#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;

int main(){
    int n,k,l;
    cin >> n >> k >> l;
    vector<mint> dp(n,0);
    dp[0] = 1;
    for(int i=1;i<(n);i++){
        cout << dp[i-1].val() << endl;
        dp[i] = dp[i-1]*l;
        if(i >= k-2) dp[i] -= i;
    }
    mint ans = dp[n-1]*l;
    cout << ans.val() << endl;
    return 0;
}
