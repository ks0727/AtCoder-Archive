#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;

int main(){
    int n; ll a,b,c;
    cin >> n >> a >> b >> c;
    vector d(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> d[i][j];
    const ll INF = 1e18;
    vector<vector<ll> > g(2*n,vector<ll>(2*n,INF));
    rep(i,n)rep(j,n) g[i][j] = d[i][j]*a;
    rep(i,n) g[i][i+n] = 0;
    for(int i=n;i<(2*n);i++){
        for(int j=n;j<(2*n);j++){
            if(i == j) g[i][j] = 0;
            else g[i][j] = d[i-n][j-n]*b+c;
        }
    }
    priority_queue<P,vector<P>, greater<P> > q;
    q.emplace(0,0);
    vector<ll> dist(2*n,INF); //現時点での最短経路を保存しておく配列
    dist[0] = 0;
    while(!q.empty()){
        auto [cost,v] = q.top(); q.pop();
        if(dist[v] < cost) continue;
        rep(u,2*n){
            if(dist[v]+g[v][u]< dist[u]){
                dist[u] = dist[v]+g[v][u];
                q.emplace(dist[v]+g[v][u],u);
            }
        }
    }
    ll ans = INF;
    ans = min(dist[n-1],dist[2*n-1]);
    cout << ans << endl;
    return 0;
}