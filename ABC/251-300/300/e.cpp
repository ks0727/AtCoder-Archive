#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>      
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    map<ll,mint> mp;
    auto f = [&](auto f, ll x)->mint{
        if(x == n) return mint(1);
        if(x > n) return mint(0);
        if(mp.count(x)) return mp[x];
        mint res = 0;
        for(int i=2;i<=6;i++){
            res += f(f,i*x)/mint(5);
        }
        return mp[x] = res;
    };
    mint ans = f(f,1);
    cout << ans.val() << endl;
    return 0;
}