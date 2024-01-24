#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll n;
    cin >> n;
    map<ll,ll> mp;
    mp[0] = 1;
    auto f = [&](auto f, ll x)->ll{
        if(mp[x] != 0) return mp[x];
        else{
            mp[x] = f(f,x/2)+f(f,x/3);
            return mp[x];
        }
    };
    ll ans = f(f,n);
    cout << ans << endl;
    return 0;
}