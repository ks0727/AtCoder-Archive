#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,e;
    cin >> n >> m >> e;
    vector<P> es;
    rep(i,e){
        int u,v;
        cin >> u >> v;
        --u; --v;
        es.emplace_back(u,v);
    }
    int q;
    cin >> q;
    vector<int> x(q);
    vector<bool> cut(e);
    rep(qi,q){
        int X;
        cin >> X;
        X--;
        x[qi] = X;
        cut[x[qi]] = true;
    }
    dsu uf(n+m);
    int now = m;
    vector<bool> on(n+m);
    rep(i,m) on[i+n] = true;
    auto merge = [&](int a, int b){
        if(uf.same(a,b)) return;
        int al = uf.leader(a), bl = uf.leader(b);
        if(on[al]) now -= uf.size(al);
        if(on[bl]) now -= uf.size(bl);
        bool ison = on[uf.leader(a)] | on[uf.leader(b)];
        uf.merge(a,b);
        int nal = uf.leader(a);
        on[nal] = ison;
        if(on[nal]) now += uf.size(nal);
    };
    rep(i,e){
        if(!cut[i]){
            merge(es[i].first,es[i].second); //初期化
        }
    }
    vector<int> ans(q);
    for(int i=q-1;i>=0;i--){
        ans[i] = now-m;
        auto [a,b] = es[x[i]];
        merge(a,b);
    }
    rep(i,q) cout << ans[i] << '\n';
    return 0;
}