#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n),s(n+1);
    rep(i,n) cin >> a[i],a[i]%=m;
    ll ans = 0;
    rep(i,n) ans += a[i]*(i+1)*(n-i);
    cout << ans << endl; 
    return 0;
}