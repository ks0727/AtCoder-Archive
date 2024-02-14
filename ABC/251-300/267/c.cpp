#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i]+a[i];
    ll val = 0;
    rep(i,m) val += (ll)(i+1)*a[i];
    const ll INF = 1e18;
    ll ans = -INF;
    rep(i,n-m+1){
        ans = max(ans,val);
        val -= (s[i+m]-s[i]);
        val += a[i+m]*(ll)m;
    }
    cout << ans << endl;
    return 0;
}   