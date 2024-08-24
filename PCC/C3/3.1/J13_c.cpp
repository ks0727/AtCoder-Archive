#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> a(n),s(2*n+1);
    rep(i,n) cin >> a[i];
    rep(i,n*2) s[i+1] = s[i] + (i<n ? a[i] : a[i-n]);
    ll l = 0, r = 1e18;
    while(r - l > 1){
        ll m = (r+l)/2;
        bool ok = false;
        int c1=0,c2=0;
        rep(i,n){
            while(c1 < (i+1+n) && s[c1]-s[i+1]<m) c1++;
            while(c2 < (i+1+n) && s[c2]-s[c1]<m) c2++;
            if(s[i+1+n] - s[c2] >= m){
                ok = true;
                break;
            }
        }
        if(ok) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}