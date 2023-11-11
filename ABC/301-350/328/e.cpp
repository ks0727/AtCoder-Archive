#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int prev,next;
    ll cost;
};

int main(){
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<Edge> edges(m);
    rep(i,m){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i].prev = u;
        edges[i].next = v;
        edges[i].cost = w;
    }
    auto f = [&](Edge a, Edge b){
        return a.cost%k < b.cost%k;
    };
    sort(edges.begin(),edges.end(),f);
    dsu uf(n);
    ll ans = 0;
    for(auto e : edges){
        if(!uf.same(e.next,e.prev)){
            uf.merge(e.next,e.prev);
            ans += (ll)e.cost % k;
            ans %= (ll)k;
        }
    }
    cout << (ll)ans << endl;
    return 0;
}