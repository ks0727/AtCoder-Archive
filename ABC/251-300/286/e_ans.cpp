#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,ll>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    const ll INF = 1e18;
    vector<vector<P> > g(n,vector<P>(n,P(INF,0)));
    rep(i,n)rep(j,n) g[i][j] = P(0,0);
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            if(s[j] == 'Y') g[i][j] = P(1,-a[j]);
        }
    }
    auto add = [&](P a, P b){
        return P(a.first+b.first, a.second+b.second);
    };

    rep(k,n){
        rep(i,n){
            rep(j,n){
                g[i][j] = min(g[i][j],add(g[i][k],g[k][j]));
            }
        }
    }
    int q;
    cin >> q;
    rep(qi,q){
        int u,v;
        cin >> u >> v;
        u--; v--;
        auto [dist,val] = g[u][v];
        if(dist == INF) cout << "Impossible" << '\n';
        else printf("%d %lld\n",dist,a[u]-val);
    }
    return 0;
}