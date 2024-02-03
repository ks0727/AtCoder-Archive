#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    auto f = [&](ll x)->bool{
        rep(i,n){
            x += (ll)a[i];
            if(x < 0) return false;
        }
        return true;
    };
    ll l = -1, r = 1e18;
    while(r-l>1){
        ll mid = (r+l)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    ll ans = r;
    rep(i,n) ans += a[i];
    cout << ans << endl;
    cout << (-1+3) % 3 << endl;
    return 0;
}