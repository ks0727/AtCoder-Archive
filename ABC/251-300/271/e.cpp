#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int b,c,idx;
    Edge(int b,int c,int idx):b(b),c(c),idx(idx){}
};

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<Edge> > g(n);
    vector<ll> costs; 
    rep(i,m){
        int a,b,c;
        cin  >> a >> b >> c;
        a--; b--;
        costs.push_back((ll)c);
        g[a].emplace_back(b,c,i);
    }
    vector<int> E(k);
    rep(i,k){
        int e;
        cin >> e;
        e--;
        E[i] = e;
    }
    vector<bool> seen(n);
    vector<vector<int> > paths;
    vector<int> test;
    auto dfs = [&](auto dfs,int v, ll d, vector<int> path)->void{ 
        if(v == n-1){
            paths.push_back(path);
            path.pop_back();
            return;
        }
        seen[v] = true;
        for(auto u : g[v]){
            if(seen[u.b]) continue;
            path.push_back(u.idx);
            dfs(dfs,u.b,d+(ll)u.c,path);
            if(path.size() > 0) path.pop_back();
        }
        seen[v] = false;
    };
    dfs(dfs,0,0,vector<int>{});
    const ll INF = 1e18;
    ll ans = INF;
    auto f = [&](vector<int> p, vector<int> e)->ll{
        int j = 0;
        int now = 0;
        ll res = 0;
        while(now < k){
            if(e[now] == p[j]){
                res += costs[p[j]];
                j++;
            }
            if(j == p.size()) return res;
            now++;
        }
        return INF;
    };
    for(auto p : paths){
        ans = min(ans,f(p,E));
    }
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
