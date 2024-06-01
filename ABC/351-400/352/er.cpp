#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,pair<int,int> >;

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> dist;
    rep(mi,m){
        int k; ll c;
        cin >> k >> c;
        vector<int> a(k);
        rep(ki,k) cin >> a[ki],a[ki]--;
        for(int i=1;i<k;i++){
            dist.push_back(P(c,make_pair(a[i],a[0])));
        }
    }
    sort(dist.begin(),dist.end());
    dsu uf(n);
    ll ans = 0;
    for(auto[cost,p] : dist){
        auto [a,b] = p;
        if(uf.same(a,b)) continue;
        uf.merge(a,b);
        ans += cost;
    }
    if(uf.size(0) != n) ans = -1;
    cout << ans << endl;
    return 0;
}
