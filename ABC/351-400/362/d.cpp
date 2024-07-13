#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,int>;

struct Edge{
    int to; ll cost;
    Edge(int to=-1,ll cost=0):to(to),cost(cost){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<Edge> > g(n);
    rep(i,m){
        int u,v; ll b;
        cin >> u >> v >> b;
        u--; v--;
        g[u].emplace_back(v,b);
        g[v].emplace_back(u,b);
    }
    priority_queue<P,vector<P>,greater<P> > q;
    q.emplace(a[0],0);
    const ll INF = 1e18;
    vector<ll> dist(n,INF);
    dist[0] = a[0];
    while(!q.empty()){
        auto [c,v] = q.top(); q.pop();
        if(c > dist[v]) continue;
        for(auto e : g[v]){
            if(e.cost + dist[v] + a[e.to] < dist[e.to]){
                dist[e.to] = e.cost+dist[v]+a[e.to];
                q.emplace(dist[e.to],e.to);
            }
        }
    }
    for(int i=1;i<n;i++) cout << dist[i] << ' ';
    cout << endl;
    return 0;
}