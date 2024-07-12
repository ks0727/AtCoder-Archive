#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    const ll INF = 1e18;
    vector<vector<ll> > dist(n,vector<ll>(n,INF));
    rep(i,n) dist[i][i] = 0;
    vector<vector<int> > g(n);
    ll ans = 0;
    rep(i,n-1){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        dist[a][b] = c;
        dist[b][a] = c;
        ans += c;
    }
    vector<ll> costs(n,-1);
    auto dfs = [&](auto dfs,int v,int p=-1)->ll{
        vector<ll> cs;
        for(int u : g[v]){
            if(u == p) continue;
            if(dist[u][v] == INF) continue;
            cs.push_back(dfs(dfs,u,v)+dist[u][v]);
        }
        if(cs.size() == 0) return costs[v] = 0;
        else{
            ll res = -1;
            rep(i,cs.size()){
                res = max(res,cs[i]);
            }
            return costs[v] = res;
        }
    };
    dfs(dfs,0,-1);
    ans *= 2;
    vector<ll> ps;
    for(int u : g[0]){
        ll uc = costs[u]+dist[0][u];
        ps.push_back(uc);
    }
    assert(ps.size() != 0);
    sort(ps.rbegin(),ps.rend());
    if(ps.size() == 1){
        ans -= ps[0];
    }else{
        ans -= ps[0];
        ans -= ps[1];
    }
    cout << ans << endl;
    return 0;
}