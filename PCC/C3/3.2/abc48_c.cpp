#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; ll x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n-1){
        ll total = a[i] + a[i+1];
        if(total <= x) continue;
        ll need = total - x;
        ans += need;
        a[i+1] = max((ll)0,a[i+1]-need);
    }
    cout << ans << endl;
    return 0;
}