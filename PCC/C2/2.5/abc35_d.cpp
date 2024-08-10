#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,int>;

struct Edge{
    int to; ll cost;
    Edge(int to, ll cost):to(to),cost(cost){}
};

int main(){
    int n,m; ll t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<Edge> > g(n);
    const ll INF = 1e18;
    vector<vector<ll> > dist(n,vector<ll>(n,INF));
    rep(mi,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b,c);
    }
    rep(i,n){
        priority_queue<P,vector<P>,greater<P> > q;
        q.emplace(0,i);
        dist[i][i] = 0;
        while (!q.empty())
        {
            auto [c,v] = q.top(); q.pop();
            if(c < dist[i][v]) continue;
            for(auto e : g[v]){
                if(dist[i][v] + e.cost < dist[i][e.to]){
                    dist[i][e.to] = dist[i][v] + e.cost;
                    q.emplace(dist[i][e.to],e.to);
                }
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        ll time = dist[0][i] + dist[i][0];
        ll use = t - time;
        ans = max(ans,use*a[i]);
    }
    cout << ans << endl;
}