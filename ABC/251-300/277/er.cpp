#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

struct Edge{
    int to,cost;
    Edge(int to=0,int cost=0):to(to),cost(cost){}
};

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<Edge> > g(2*n);
    rep(i,m){
        int u,v,a;
        cin >> u >> v >> a;
        u--; v--;
        if(a == 1){
            g[u].push_back({v,1});
            g[v].push_back({u,1});
        }else{
            g[u+n].push_back({v+n,1});
            g[v+n].push_back({u+n,1});
        }
    }
    rep(i,k){
        int s;
        cin >> s;
        s--;
        g[s].push_back({s+n,0});
        g[s+n].push_back({s,0});
    }
    const int INF = 1e9;
    vector<int> dist(n*2,INF);
    dist[0] = 0;
    priority_queue<P,vector<P>,greater<P> > q;
    q.emplace(0,0);
    while(!q.empty()){
        auto [d,v] = q.top(); q.pop();
        if(dist[v] != d) continue;
        for(auto e : g[v]){
            if(d+e.cost < dist[e.to]){
                dist[e.to] = d+e.cost;
                q.emplace(dist[e.to],e.to);
            }
        }
    }
    int ans = INF;
    ans = min(dist[n-1],dist[2*n-1]);
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}