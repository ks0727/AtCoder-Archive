#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    ll n;
    cin >> n;
    const int M = 2e6+5;
    vector<bool> isp(M,true);
    isp[0] =isp[1] = false;
    for(ll i=2;i<=M;i++){
        if(!isp[i]) continue;
        for(ll j=i*2;j<=M;j+=i){
            isp[j] = false;
        }
    }
    ll ans = 0;
    vector<ll> ps;
    rep(i,M+1) if(isp[i]) ps.emplace_back(i);
    rep(i,ps.size()){
        ll x = 1;
        rep(j,8) x *= ps[i];
        if(x > n) break;
        ans++;
    }
    int r = ps.size()-1;
    for(int l=0;l<ps.size();l++){
        while(r > l && (ll)ps[r]*ps[r]*ps[l]*ps[l] > n) r--;
        if(r < l) break;
        ans += r-l;
    }
    cout << ans << endl;
    return 0;
}