#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll s = 0; //sは総和
    rep(i,n) s+= a[i];
    ll x = s/n, r = s%n;
    vector<ll> b(n,x);
    rep(i,r) b[i]++;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = 0;
    rep(i,n) ans += abs(a[i] - b[i]);
    cout << ans /2 << endl;
    return 0;
}