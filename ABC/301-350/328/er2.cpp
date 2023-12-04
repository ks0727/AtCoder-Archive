#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int a,b; ll cost;
    Edge(int a,int b, ll cost): a(a),b(b),cost(cost){}
};

int main(){
    int n,m; ll k;
    cin >> n >> m >> k;
    vector<Edge> es;
    rep(i,m){
        int u,v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        es.emplace_back(u,v,w);
    }
    const ll INF = 1e18;
    ll ans = INF;
    auto f = [&](auto f, int i,vector<int> is)->void{
        if(is.size() == n-1){
            dsu uf(n);
            ll now = 0;
            rep(j,n-1){
                if(uf.same(es[is[j]].a,es[is[j]].b)) return;
                uf.merge(es[is[j]].a,es[is[j]].b);
                now += es[is[j]].cost;
                now %= k;
            }
            ans = min(ans,now);
            return;
        }
        if(i == m) return;
        f(f,i+1,is);
        is.push_back(i);
        f(f,i+1,is);
    };
    f(f,0,vector<int>(0));
    cout << ans << endl;
    return 0;
}