#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    const int M = 25;

    vector<ll> d(M);
    rep(k,M){
        int mod = 1<<k;
        vector<ll> sum(mod),cnt(mod);
        ll now = 0;
        rep(i,n){
            sum[a[i]%mod] += a[i];
            sum[a[i]%mod]++;
            int b = (mod-a[i]%mod)%mod;
            now += sum[b];
            now += cnt[b]*a[i];
        }
        d[k] = now;
    }
    rep(k,M-1) d[k] -= d[k+1];
    ll ans = 0;
    rep(k,M) ans += d[k]>>k;
    cout << ans << endl;
    return 0;
}