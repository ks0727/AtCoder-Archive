#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n,m;
    cin >> n >> m;
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    set<P> ng;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        ng.emplace(x,y);
    }
    map<P,mint> mp;
    mp[P(0,0)] = 1;
    rep(i,n){
        map<P,mint> mp2;
        swap(mp,mp2);
        for(auto [p,cnt] : mp2){
            if(!ng.count(P(p.first+a,p.second+b))) mp[P(p.first+a,p.second+b)] += cnt;
            if(!ng.count(P(p.first+c,p.second+d))) mp[P(p.first+c,p.second+d)] += cnt;
            if(!ng.count(P(p.first+e,p.second+f))) mp[P(p.first+e,p.second+f)] += cnt;
        }
    }
    mint ans = 0;
    for(auto[p,cnt] : mp){
        ans += cnt;
    }
    cout << ans.val() << endl;
    return 0;
}

