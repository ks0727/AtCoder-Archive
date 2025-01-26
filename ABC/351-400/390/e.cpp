#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll n,x;
    cin >> n >> x;
    vector<int> v(n);
    vector<ll> a(n),c(n);
    rep(i,n) cin >> v[i] >> a[i] >> c[i], v[i]--;
    const ll INF = 1e18;
    vector<vector<ll> > cal(x+1,vector<ll>(3,-INF)); //カロリー消費がjの時のビタミンkの摂取量の最大値
    cal[0][0] = cal[0][1] = cal[0][2] = 0;
    rep(k,3){
        rep(i,n){
            if(v[i] != k) continue;
            for(int j=x;j>=0;j--){
                if(j-c[i] >= 0 && cal[j-c[i]][k] != -INF) cal[j][k] = max(cal[j-c[i]][k]+a[i],cal[j][k]);
            }
        }
    }
    ll r = 1e9, l = 0;
    while(r-l > 1){
        ll mid = (r+l)/2;
        auto f = [&](ll m){ //カロリー消費をx以下として, 全てのビタミンをm以上接種できるかどうか
            ll now = 0;
            rep(k,3){
                rep(j,x+1){
                    if(cal[j][k] >= m){
                        now += j;
                        break;
                    }
                    if(j==x) return false;
                }
            }
            //cout << now << endl;
            return now <= x;
        };
        if(f(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}