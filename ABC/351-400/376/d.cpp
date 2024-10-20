#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<pair<int,int> > es;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        es.emplace_back(a,b);
    }
    const int INF = 1001001001;
    vector<int> dist(n,INF);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int u : g[v]){
            if(dist[u] != INF) continue;
            dist[u] = dist[v]+1;
            q.push(u);
        }
    }
    int ans = INF;
    rep(i,m){
        auto [a,b] = es[i];
        if(b == 0) ans = min(ans,dist[a]+1);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}