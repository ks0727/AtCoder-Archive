#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;
const ll mod = 998244353;

int main(){
    ll n,m; cin >> n >> m;
    ll ans = 0;
    rep(i,60)if(m&(ll)(1<<i)){
        ll x = n;
        ll p2 = (ll)1<<i;
        ll l = x/(2*p2);
        ll res = l*p2;
        ll r = x%(2*p2);
        if(r >= p2) res += (r-p2+1);
        ans += res;
        ans %= mod;
    }
    cout << (ans+mod)%mod << endl;
    return 0;
}