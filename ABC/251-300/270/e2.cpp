#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto f = [&](ll m)->bool{ //m周した時に食べるりんごはk個以下か？
        ll x = k;
        rep(i,n){
            if(a[i] >= m){
                x -= m;
            }else{
                x -= a[i];
            }
        }
        return x >=0;
    };
    ll l = 0, r = 1e18;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(f(mid)) l = mid;
        else r = mid;
    }
    rep(i,n){
        ll d = min(a[i],l);
        a[i] -= d;
        k -= d;
    }
    rep(i,n){
        if(k == 0) break;
        if(a[i] > 0){
            k--;
            a[i]--;
        }
    }
    rep(i,n) cout << a[i] << ' ';
    cout << endl;
    return 0;
}