#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n,x;
    cin >> n>> x;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<ll> s(n+1);
    rep(i,n) s[i+1] = s[i]+a[i]+b[i];
    const ll INF = 3e18;
    ll ans = numeric_limits<ll>::max();
    rep(i,n){
        if(i+1 > x) break;
        ll now = s[i+1];
        now += b[i]*(ll)(x-i-1);
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}