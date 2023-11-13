#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int a,b; ll w;
    Edge(int a, int b, ll w):a(a),b(b),w(w){}
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
    ll ans  = INF;
    auto dfs = [&](auto dfs,int i,vector<int> is)->void{
        if(is.size() == n-1){
            dsu uf(n);
            bool ok = true; //グラフは木か？
            ll now = 0;
            for(int ei : is){
                auto e = es[ei];
                if(uf.same(e.a,e.b)) ok = false;
                uf.merge(e.a,e.b);
                now = (now+e.w)%k;
            }
            if(ok) ans = min(ans,now);
            return;
        }
        if(i == m) return;
        dfs(dfs,i+1,is);
        is.push_back(i);
        dfs(dfs,i+1,is);
    };
    dfs(dfs,0,{});
    cout << ans << endl;
    return 0;
}