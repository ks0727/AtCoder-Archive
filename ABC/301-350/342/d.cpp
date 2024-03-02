#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    const int M = 200005;
    auto comb2 = [&](ll x){
        ll res = x*(x-1)/2;
        return res;
    };
    rep(i,n){
        ll now = 1;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%(j*j) == 0) now = (ll)j*j;
        }
        a[i] /= now;
    }
    ll ans = 0;
    vector<ll> cnt(M);
    rep(i,n) cnt[a[i]]++;
    ans += cnt[0]*(n-1);
    ans -= comb2(cnt[0]);
    for(int i=1;i<M;i++) ans += comb2(cnt[i]);
    cout << ans << endl;
    return 0;
}