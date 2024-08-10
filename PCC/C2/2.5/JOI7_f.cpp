#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,int>;

int main(){
    int n,k;
    cin >> n >> k;
    const ll INF = 1e18;
    vector<vector<P> > g(n,vector<P>(n));
    rep(i,n)rep(j,n) g[i][j] = P(INF,j);
    rep(ki,k){
        int x; cin >> x;
        if(x == 0){
            int a,b;
            cin >> a >> b;
            a--; b--;
            priority_queue<P,vector<P>,greater<P> > q;
            q.emplace(0,a);
            vector<ll> dist(n,INF);
            dist[a] = 0;
            while(!q.empty()){
                auto [c,v] = q.top(); q.pop();
                if(dist[v] < c) continue;
                for(auto e : g[v]){
                    if(e.first == INF) continue;
                    if(dist[v] + e.first < dist[e.second]){
                        dist[e.second] = dist[v] + e.first;
                        q.emplace(dist[e.second],e.second);
                    }
                }
            }
            if(dist[b] == INF) cout << -1 << endl;
            else cout << dist[b] << endl;
        }else{
            int a,b; ll c;
            cin >> a >> b >> c;
            a--; b--;
            if(g[a][b].first < c) continue;
            g[a][b] = P(c,b);
            g[b][a] = P(c,a);
        }
    }
}