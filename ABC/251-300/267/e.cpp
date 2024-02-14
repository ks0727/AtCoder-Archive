#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;

struct Edge{
    set<int> ns; ll cost; ll self;
    Edge(set<int> ns={},ll cost=0, ll self=0):ns(ns),cost(cost),self(self){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<Edge> g(n);
    rep(i,n) g[i].self = a[i];
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].ns.insert(v);
        g[u].cost += a[v];
        g[v].ns.insert(u);
        g[v].cost += a[u];
    }
    vector<P> es;
    rep(i,n){
        es.emplace_back(a[i],i);
    }
    sort(es.begin(),es.end());
    ll ans = 0;
    while(es.size() > 0){
        auto [c,v] = es.back(); es.pop_back();
        ll cur = 0;
        for(int x : g[v].ns){
            g[x].ns.erase(v);
            g[x].cost -= c;
            cur += g[x].self;
        }
        ans = max(cur,ans);
    }
    cout << ans << endl;
    return 0;
}