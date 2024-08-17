#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

ll sm(ll x){
    ll res = (ll)x*(x+1)/2;
    return res;
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = sm(n);
    ll ad = n / a;
    ans -= (ll)a * sm(ad);
    ll bd = n / b;
    ans -= (ll)b*sm(bd);
    ll lc = lcm(a,b);
    ll ld = n / lc;
    ans += (ll)lc * sm(ld);
    cout << ans << endl;
    return 0;
}