#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int next;
    ll cost;
};

void solve(vector<vector<Edge> > g,int n,vector<ll> a){
    int u,v;
    cin >> u >> v;
    u--; v--;
    vector<bool> seen(n);
    ll cost = 0;
    const ll INF = 1e18;
    ll path = INF;
    auto dfs = [&](auto dfs, Edge now,ll current_cost,int current_path) ->void{
        if(now.next == v){
            if(current_path <= path){
                path = current_path;
                cost = max(current_cost,cost);
            }
            return;
        }
        current_cost += now.cost;
        seen[now.next] = true;
        for(auto nx : g[now.next]){
            if(seen[nx.next]) continue;
            dfs(dfs,nx,current_cost,current_path+1);
        }
        seen[now.next] = false;
    };
    dfs(dfs,{u,a[u]},0,0);
    if(path == INF) cout << "Impossible" << endl;
    else cout << path << ' ' << cost << endl;
}
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<Edge> > g(n);
    rep(i,n)rep(j,n){
        char exist;
        cin >> exist;
        if(exist == 'Y'){
            g[i].push_back({j,a[j]});
            g[j].push_back({i,a[i]});
        }
    }
    int q;
    cin >> q;
    rep(i,q){
        solve(g,n,a);
    }
    return 0;
}