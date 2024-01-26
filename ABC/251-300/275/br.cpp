#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    vector<ll> a(6);
    const ll mod = 998244353;
    rep(i,6){
        ll x;
        cin >> x;
        x %= mod;
        a[i] = x;
    }
    ll abc = (a[0]*a[1]%mod)*a[2]%mod;
    ll cde = (a[3]*a[4]%mod)*a[5]%mod;
    ll ans = (abc-cde)%mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}