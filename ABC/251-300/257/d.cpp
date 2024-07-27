#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<ll,int>;

ll abd(P a,P b){
    ll res = abs(a.first-b.first) + abs(a.second-b.second);
    return res;
};

int main(){
    int n;
    cin >> n;
    vector<P> pos(n);
    vector<ll> p(n);
    rep(i,n) cin >> pos[i].first >> pos[i].second >> p[i];
    const ll INF = 1e18;
    vector<vector<ll> > dist(n,vector<ll>(n,INF));
    rep(i,n){
        rep(j,n){
            dist[i][j] = (abd(pos[i],pos[j])+p[i]-1)/p[i];
        }
    }
    vector<vector<ll> > d(n,vector<ll>(n,INF));
    rep(k,n){
        rep(i,n){
            rep(j,n){
                dist[i][j] = min(max(dist[i][k],dist[k][j]),dist[i][j]);
            }
        }
    }
    ll ans = INF;
    rep(i,n){
        ll now = 0;
        for(auto x : dist[i]){
            now = max(now,x);
        }
        ans = min(now,ans);
    }
    cout << ans << endl;
    return 0;
}