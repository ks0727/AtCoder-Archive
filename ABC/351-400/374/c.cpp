#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> k(n);
    rep(i,n) cin >> k[i];
    int n2 = 1<<n;
    ll ans = 1e18;
    rep(i,n2){
        ll a=0,b=0;
        rep(j,n){
            if(i >> j&1){
                a += k[j];
            }else{
                b += k[j];
            }
        }
        ll now = max(a,b);
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}