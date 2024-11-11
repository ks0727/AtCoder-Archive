#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,ll>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<P> ps(m);
    rep(i,m) cin >> ps[i].first,ps[i].first--;
    rep(i,m) cin >> ps[i].second;
    sort(ps.begin(),ps.end());
    ll sum = 0;
    rep(i,m) sum += ps[i].second;
    if(sum != n){
        cout << -1 << endl;
        return 0;
    }
    ll prev = n-1;
    ll ans = 0;
    for(int i=m-1;i>=0;i--){
        auto [idx,cnt] = ps[i];
        if(prev-idx+1 < cnt){
            cout << -1 << endl;
            return 0;
        }
        ans += (prev*cnt) - (idx*cnt) - (cnt*(cnt-1)/2);
        prev = prev - cnt;
    }
    cout << ans << endl;
}