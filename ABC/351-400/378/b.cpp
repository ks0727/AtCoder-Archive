#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll> > ps(n);
    rep(i,n) cin >> ps[i].first >> ps[i].second;
    int q;
    cin >> q;
    rep(qi,q){
        ll t,d;
        cin >> t >> d;
        t--;
        if(d <= ps[t].second){
            cout << ps[t].second << endl;
            continue;
        }else{
            ll b = (d-ps[t].second+ps[t].first-1)/ps[t].first;
            ll ans = b*ps[t].first+ps[t].second;
            cout << ans << endl;
        }
    }
    return 0;
}