#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n; ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    const ll INF = 1e15;
    ll l = 0,r = INF;
    while(r-l>1){
        ll mid = (l+r)/2;
        auto f = [&](ll x){
            ll res = 0;
            rep(i,n) res += min(x,a[i]);
            return res <= m;
        };
        if(f(mid)) l = mid;
        else r = mid;
    }
    if(l > m) cout << "infinite" << endl;
    else cout << l << endl;
    return 0;
}