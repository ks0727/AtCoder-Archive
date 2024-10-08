#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using mint = modint998244353;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n),s(n+1);
    rep(i,n) cin >> a[i];
    rep(i,n) s[i+1] = s[i] + a[i];
    map<ll,mint> mp;    
    vector<mint> dp(n+1);
    mint sum = 0;
    dp[0] = 1;
    mp[0] = 1;
    rep(i,n){
        sum += dp[i];
        mp[s[i]] += dp[i];
        dp[i+1] = sum - mp[s[i] - k];
    }
    cout << dp[n].val() << endl;
    return 0;
}