#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using mint = modint;
using ll = long long;

int main(){
    int a; ll x,m;
    cin >> a >> x >> m;
    if(a == 1){
        cout << x%m << endl;
        return 0;
    }
    auto f = [&](auto f, ll now, int a)->ll{
        if(now == 0) return 1;
        if(now == 1) return a;
        if(now % 2 == 0){
            ll y = f(f,now/2,a) % m;
            return y * y;
        }else{
            ll y = f(f,now/2,a) % m;
            return y*y*a%m;
        }
    };

    ll ans = f(f,x,a);
    ans += m-1;
    ans %= m;
    ans *= f(f,m-2,a-1);
    cout << ans%m << endl;
    return 0;
}