#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    dsu uf(n);
    vector<pair<int,int> > edges;
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        if(a[u] == a[v]) uf.merge(u,v);
        edges.emplace_back(u,v);
    }
    vector<vector<int> > g(n);
    for(auto [u,v] : edges){
        u = uf.leader(u);
        v = uf.leader(v);
        if(u == v) continue;
        if(a[u] > a[v]) swap(u,v);
        g[u].push_back(v);
    }
    vector<int> vs;
    rep(i,n){
        if(uf.leader(i) == i){
            vs.push_back(i);
        }
        sort(vs.begin(),vs.end(),[&](int u,int v){
            return a[u] < a[v];
        });
    }
    const int INF = 1001001001;
    vector<int> dp(n,-INF);
    dp[uf.leader(0)] = 1;
    for(int v : vs){
        for(int u : g[v]){
            dp[u] = max(dp[u],dp[v]+1);
        }
    }
    int ans = dp[uf.leader(n-1)];
    if(ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}