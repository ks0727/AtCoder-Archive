#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    const int mod = 100000000;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    vector<ll> sa(n+1);
    rep(i,n) sa[i+1] = sa[i] + a[i];
    ll ans = 0;
    rep(i,n-1){
        int pi = lower_bound(a.begin(),a.end(),mod-a[i]) - a.begin();
        if(pi == n){ //ない時
            ans += sa[n]-sa[i]+a[i]*(n-2);
        }else{
            pi = max(i+1,pi);
            ll before = sa[pi]-sa[i+1]+(pi-i-1)*a[i];
            ans += before;
            ll add = a[i] * (n-pi);
            ll after = (add+sa[n]-sa[pi])%mod;
            ans += after;
        }
    }
    cout << ans<< endl;
    return 0;
}