#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll g = gcd(n,m);
    ll lc = n*(m/g);
    ll ln = lc/n, lm = lc/m;
    auto f = [&](ll x)->bool{
        ll res = x/n+x/m;
        res -= 2*(x/lc);
        return res >= k;
    };
    ll r = 1e18, l = -1;
    while(r-l>1){
        ll mid = (r+l)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}