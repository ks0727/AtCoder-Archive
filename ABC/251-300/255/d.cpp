#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i] + a[i];
    while(q--){
        ll x;
        cin >> x;
        if(x <= a[0]){
            ll ans = s[n] - x*n;
            cout << ans << endl;
        }else if(x >= a[n-1]){
            ll ans = x*n - s[n];
            cout << ans << endl;
        }else{
            int id = lower_bound(a.begin(),a.end(),x) - a.begin();
            ll ans = x*id - s[id];
            ans += s[n] - s[id];
            ans -= x*(n-id);
            cout << ans << endl;
        }
    }
    return 0;
}