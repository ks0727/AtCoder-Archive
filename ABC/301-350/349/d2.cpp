#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<ll,ll>;
int main(){
    ll l,r; cin >> l >> r;
    ll ans = 0;
    auto f = [&](ll x)->P{
        assert(x != 0);
        int cnt = 0;
        while(x%2==0){
            x /= 2;
            cnt++;
        }
        return P(cnt,x);
    };
    auto g = [&](ll x,ll y)->ll{
        ll res = 1;
        rep(i,x){
            res *= 2;
        }
        res*=y;
        return res;
    };
    vector<P> ps;
    auto dfs = [&](auto dfs,ll l,ll r)->void{
        auto [x1,y1] = f(l);
        auto [x2,y2] = f(r);
        ll res = 0;
        if(x1 == x2 && y2 == y1+1){
            ans++;
            return;
        }
        if(x2 == x1+1 && y1 == y2){
            ans++;
            return;
        }
        if(x1 == 0 && r - l == 1){
            ans++;
            return;
        }
        if(x2 == 0 && r - l ==1){
            ans++;
            return;
        }
        cout << l << ' ' <<r << endl;
        dfs(dfs,g(x1,y1),g(x1,y1+1));
        dfs(dfs,g(x1,y1+1),g(x2,y2-1));
        dfs(dfs,g(x2,y2-1),g(x2,y2));
    };
    dfs(dfs,l,r);
    cout << ans << endl;
    return 0;
}