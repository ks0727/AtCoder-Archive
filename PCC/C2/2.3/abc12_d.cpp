#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,int>;

int main(){
    int n,m;
    cin >> n>> m;
    const ll INF = 1e18;
    vector<vector<ll> > dist(n,vector<ll>(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(mi,m){
        int a,b; ll t;
        cin >> a >> b >> t;
        a--; b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    
    ll ans = INF;
    rep(i,n){
        ll now = 0;
        rep(j,n){
            if(dist[i][j] != INF) now = max(now,dist[i][j]);
        }
        ans = min(now,ans);
    }
    cout << ans << endl;
    return 0;
}
