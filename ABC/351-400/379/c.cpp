#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> x(m),a(m);
    rep(i,m) cin >> x[i],x[i]--;
    ll sum = 0;
    rep(i,m) cin >> a[i],sum += a[i];
    if(sum != n){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<ll,ll> > ps;
    rep(i,m){
        ps.emplace_back(x[i],a[i]);
    }
    sort(ps.begin(),ps.end());
    ll prev = n-1;
    ll ans = 0;
    for(int i=m-1;i>=0;i--){
        if(prev-ps[i].first+1 < ps[i].second){
            cout << -1 << endl;
            return 0;
        }
        ans += ps[i].second*prev-ps[i].second*ps[i].first-(ps[i].second*(ps[i].second-1)/2);
        prev = prev - ps[i].second;
    }
    if(prev != -1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}