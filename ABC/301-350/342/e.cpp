#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;
struct Edge{
    ll l,d,k,c,to;
    Edge(ll l, ll d,ll k, ll c, ll to):l(l),d(d),k(k),c(c),to(to){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        ll l,d,k,c; ll a,b;
        cin >> l >> d >> k >> c >> a >> b;
        a--; b--;
        g[a].emplace_back(l,d,k,c,b);
    }
    const ll INF = 1e18;
    vector<ll> dist(n,INF);
    priority_queue<P,vector<P>,greater<P> > q;
    q.emplace()
}