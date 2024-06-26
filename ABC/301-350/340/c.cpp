#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    map<ll,ll> mp;
    mp[1] = 1;
    auto f = [&](auto f,ll x)->ll{
        if(x == 1) return 1;
        if(mp.count(x)) return mp[x];
        return mp[x] = f(f,x/2)+f(f,(x+1)/2);
    };
    f(f,n);
    ll ans = 0;
    auto f2 = [&](auto f2,ll x)->void{
        if(x == 1) return;
        ans += mp[x];
        f2(f2,x/2);
        f2(f2,(x+1)/2);
    };
    f2(f2,n);
    cout << ans << endl;
    return 0;
}