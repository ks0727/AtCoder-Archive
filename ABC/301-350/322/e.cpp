#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,k,p;
    cin >> n >> k >> p;
    map<vector<int>,ll> dp;
    dp[vector<int>(k)] = 0;
    rep(i,n){
        int c;
        cin >> c;
        vector<int> a(k);
        rep(j,k) cin >> a[j];
        auto old = dp;
        for(auto [_d,val] : old){
            vector<int> d = _d;
            rep(j,k) d[j] += min(d[j]+a[j],p);
            if(dp.count(d)) dp[d] = min(dp[d],val+c);
            else dp[d] = val + c;
        }
    }
    vector<int> t(k,p);
    if(dp.count(t)) cout << dp[t] << endl;
    else cout << -1 << endl;
    return 0;
}
