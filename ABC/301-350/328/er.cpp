#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int next; ll cost;
    Edge(int next, ll cost):cost(cost),next(next){}
};

int main(){
    int n,m; ll k;
    cin >> n >> m >> k;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int u,v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    vector<bool> used(n);
    used[0] = true;
    const ll INF = 1e18;
    ll ans = INF;
    vector<int> visited;
    int depth = 0;
    auto dfs = [&](auto dfs, int v, ll c)->void{
        depth++;
        if(depth == n){
            ans = min(ans,c);
            used[v] = false;
        }
        used[v] = true;
        visited.push_back(v+1);
        rep(i,visited.size()){
            cout << visited[i] << ' ';
        }
        cout << endl;
        for(auto u : g[v]){
            if(used[u.next]) continue;
            ll nc = c+u.cost;
            nc %= k;
            dfs(dfs,u.next,nc);
            used[u.next] = false;
            visited.pop_back();
            depth--;
        }
    };
    dfs(dfs,0,k);
    cout << ans % k << endl;
    return 0;
}