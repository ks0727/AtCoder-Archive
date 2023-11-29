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
    const ll INF = 1e18;
    ll ans = INF;
    queue<int> q;
    ll now = k;
    q.push(0);
    int nv = 0;
    vector<int> visit;
    while(!q.empty()){
        int v = q.front(); q.pop();
        visit.push_back(v+1);
        rep(i,visit.size()){
            cout << visit[i] << ' ';
        }
        cout << endl;
        used[v] = true;
        nv++;
        cout << now << endl;
        if(nv == n){
            ans = min(ans,now);
        }
        for(auto u : g[v]){
            if(used[u.next]) continue;
            q.push(u.next);
            now += u.cost;
            now %= k;
        }
    }
    cout << ans << endl;
    return 0;
}