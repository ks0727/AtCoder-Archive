#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    ll a,b,c,d,e,f;
    const ll mod = 998244353;
    cin >> a >> b >> c >> d >> e >> f;
    a %= mod;
    b %= mod;
    c %= mod;
    d %= mod;
    e %= mod;
    f %= mod;
    ll ans1 = a;
    ans1 *= b;
    ans1 %= mod;
    ans1 *= c;
    ans1 %= mod;
    ll ans2 = d;
    ans2 *= e;
    ans2 %= mod;
    ans2 *= f;
    ans2 %= mod;
    ll ans = ans1%mod - ans2%mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}