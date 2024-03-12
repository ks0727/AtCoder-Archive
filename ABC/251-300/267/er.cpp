#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = tuple<ll,ll,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<vector<int> > g(n);
    rep(i,n) cin >> a[i];
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<P,vector<P>,greater<P> > q;
    vector<ll> costs(n);
    rep(i,n){
        ll cost = 0;
        rep(j,g[i].size()) cost += a[g[i][j]];
        q.emplace(cost,-a[i],i);
        costs[i] = cost;
    }
    const ll INF = 1e18;
    ll ans = -INF;
    vector<bool> erased(n);
    while(!q.empty()){
        auto [c,sc,v] = q.top(); q.pop();
        if(erased[v]) continue;
        erased[v] = true;
        ans = max(ans,c);
        for(int u : g[v]){
            if(erased[u]) continue;
            costs[u] += sc;
            q.emplace(costs[u],-a[u],u);
        }
    }
    cout << ans << endl;
    return 0;
}