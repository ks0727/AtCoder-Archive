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
        if(x == 1) return 0;
        if(mp.count(x)) return mp[x];
        mp[x] = x + f(f,x/2)+f(f,(x+1)/2);
        return mp[x];
    };
    ll ans = f(f,n);
    cout << ans << endl;
    return 0;
}