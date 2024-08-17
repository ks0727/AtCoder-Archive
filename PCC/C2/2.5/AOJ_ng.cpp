#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using T = tuple<ll,int,int>;

int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<T> es;
    rep(i,m){
        int v,u; ll c;
        cin >> v >> u >> c;
        es.emplace_back(c,v,u);
    }
    const ll INF = 1e18;
    vector<ll> dist(n,INF);
    dist[r] = 0;
    rep(i,n){
        for(auto e : es){
            auto [c,v,u] = e;
            if(dist[v] == INF) continue;
            if(dist[v] + c < dist[u]){
                dist[u] = dist[v]+c;
                if(i == n-1){
                    cout << "NEGATIVE CYCLE" << endl;
                    return 0;
                }
            }
        }
    }
    rep(i,n){
        if(dist[i] != INF)cout << dist[i] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}