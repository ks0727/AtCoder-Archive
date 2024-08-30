#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,w;
    cin >> n >> w;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(0);
    vector<bool> ok(w+1);
    rep(i,n+1){
        rep(j,n+1){
            rep(k,n+1){
                if(i == j && i != n) continue;
                if(j == k && j != n) continue;
                if(i == k && i != n) continue;
                ll x = (n >= 3 ? a[i]+a[j]+a[k]:(n == 2? a[i]+a[j]:a[i])); 
                if(x > w) continue;
                ok[x] = true;
            }
        }
    }
    ll ans = 0;
    rep(i,w+1){
        if(ok[i]) ans++;
    }
    cout << ans-1 << endl;
    return 0;
}