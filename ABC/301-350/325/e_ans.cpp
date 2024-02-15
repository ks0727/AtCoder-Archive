#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;

int main(){
    int n; ll a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<int> > d(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >> d[i][j];

    const ll INF = 1e18;
    auto dijk = [&](int sv, ll b , ll c){
        vector<ll> dist(n,INF);
        dist[sv] = 0;
        vector<bool> done(n);
        rep(ni,n){
            P best(INF,0);
            rep(i,n) if(!done[i]) best = min(best,P(dist[i],i));
            int v = best.second;
            rep(i,n){
                dist[i] = min(dist[i],dist[v]+d[v][i]*b+c);
            }
        }
        return dist;
    };
    auto d1 = dijk(0,a,0);
    auto d2 = dijk(n-1,b,c);
    ll ans = INF;
    rep(i,n) ans = min(ans,d1[i]+d2[i]);
    cout << ans << endl;
    return 0;
}
