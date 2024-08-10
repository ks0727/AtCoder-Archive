#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll x,a,d,n;
    cin >> x >> a >> d >> n;
    ll ans = 8e18;
    ll mx = a + (n-1)*d;
    if(mx < a) swap(a,mx);
    if(d < 0) d *= -1;
    if(x <= a) cout << a- x << endl;
    else if(x >= mx) cout << x- mx << endl;
    else{
        ll k1 = (x-a)/d;
        ll x1 = a + k1*d;
        ll x2 = a + (k1+1)*d;
        ll ans = 8e18;
        ans = min(x-x1,x2-x);
        cout << ans << endl;
    }
    return 0;
}
