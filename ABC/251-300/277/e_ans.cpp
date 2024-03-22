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
    int n2 = n*2;
    vector<vector<Edge> > g(n2);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        if(c == 1){
            g[a].emplace_back(b,1);
            g[b].emplace_back(a,1);
        }else{
            g[a+n].emplace_back(b,1);
            g[b+n].emplace_back(a,1);
        }
    }
    rep(i,k){
        int v;
        cin >> v;
        v--;
        g[v].emplace_back(v+n,0);
        g[v+n].emplace_back(v,0);
    }
    const int INF = 1001001001;
    vector<int> dist(n2,INF);
    dist[0] = 0;
    deque<P> q;
    q.emplace_back(0,0);
    while(!q.empty()){
        auto [d,v] = q.front(); q.pop_front();
        if(dist[v] != d) continue;
        for(Edge e : g[v]){
            int nd = d+e.cost;
            if(nd >= dist[e.to]) continue;
            dist[e.to] = nd;
            if(e.cost == 1) q.emplace_back(nd,e.to);
            else q.emplace_front(nd,e.to);
        }
    }
    int ans = min(dist[n-1],dist[n2-1]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}