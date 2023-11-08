#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(b.begin(),b.end());
    ll ans = -1;
    rep(i,n){
        int j = upper_bound(b.begin(),b.end(),(ll)a[i]+d) - b.begin() - 1;
        if(j < 0) continue;
        if((ll)b[j] >= (ll)a[i] - d) ans = max(ans,(ll)a[i]+b[j]);
    }
    cout << ans << endl;
    return 0;
}