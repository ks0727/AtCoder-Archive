#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

void chmax(ll &x, ll y){
    x = max(x,y);
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<vector<pair<ll,ll>> > foods(3);
    rep(i,n){
        int v,a,c;
        cin >> v >> a >> c;
        v--;
        foods[v].emplace_back(a,c);
    }   
    vector d(3,vector<ll>(x+1));
    rep(v,3){
        vector<ll> dp(x+1); //jカロリーを摂った時のビタミンvの摂取量の最大値
        for(auto [a,c] : foods[v]){
            for(int i=x;i>=c;i--){
                chmax(dp[i],dp[i-c]+a);
            }
        }
        d[v] = dp;
    }
    ll l =0, r = 1001001001;
    while(r-l>1){
        ll mid = (l+r)/2;
        auto f = [&](ll m){
            ll tot = 0;
            rep(v,3){
                if(d[v][x] < m) return false;
                ll need = lower_bound(d[v].begin(),d[v].end(),mid) - d[v].begin();
                tot == need;
            }
            return tot <= x;
        };
        if(f(mid)) l = mid; else r = mid;
    }
    return 0;
}