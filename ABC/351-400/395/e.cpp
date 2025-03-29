#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<long long,int>;
int main(){
    long long n,m,x;
    cin >> n >> m >> x;
    vector<vector<P> > g(n*2);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(1,b);
        g[b+n].emplace_back(1,a+n);
    }
    rep(i,n){
        g[i].emplace_back(x,i+n);
        g[i+n].emplace_back(x,i);
    }
    const long long INF = 1e18;
    vector<long long> dist(n*2,INF);
    dist[0] = 0;
    priority_queue<P,vector<P>,greater<P> > q;
    q.emplace(0,0);
    while(!q.empty()){
        auto [c,v] = q.top(); q.pop();
        if(c != dist[v]) continue;
        for(auto [nc,u] : g[v]){
            if(dist[v] + nc < dist[u]){
                dist[u] = dist[v]+nc;
                q.emplace(dist[u],u);
            }
        }
    }
    long long ans = min(dist[n-1],dist[2*n-1]);
    cout << ans << endl;
    return 0;
}