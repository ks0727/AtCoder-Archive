#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
    int n,m; ll d;
    cin >> n >> m >> d;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll  ans = -1;
    rep(i,n){
        ll left = a[i] - d;
        ll right = a[i] + d;
        int j = upper_bound(b.begin(),b.end(),right)-b.begin();
        if(j > 0) {
            ll x = b[j-1];
            if(left <= x){
                ans = max(ans,a[i]+x);
            }
        }
    }
    cout << ans << endl;
    return 0;
}