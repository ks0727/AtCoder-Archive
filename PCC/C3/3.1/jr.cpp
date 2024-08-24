#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    ll R,B;
    cin >> R >> B;
    ll x,y;
    cin >> x >> y;

    ll l = 0, r= min(R/x,B);

    auto f = [&](ll m)->ll{
        return m + min(R-m*x,(B-m)/y);
    };

    while(r - l > 10){
        ll ml = (l*2+r)/3; 
        ll mr = (l+r*2)/3;

        if(f(ml) < f(mr)) l = ml;
        else r = mr;
    }
    ll ans = 0;
    for(ll i=l;i<=r;i++){
        ans = max(ans,f(i));
    }
    cout << ans << endl;
    return 0;
}