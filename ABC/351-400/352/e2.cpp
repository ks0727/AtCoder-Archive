#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    ll cost; int a,b;
    Edge(ll cost, int a,int b):cost(cost),a(a),b(b){}
    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    const ll INF = 1e18;
    vector<vector<ll> > costs(n,vector<ll>(n,INF));
    set<Edge> es;
    dsu uf1(n);
    rep(mi,m){
        int k; ll c;
        cin >> k >> c;
        vector<int> a(k);
        rep(j,k){
            cin >> a[j];
            a[j]--;
        } 
        rep(j,k){
            for(int l=j+1;l<k;l++){
                if(a[j] > a[l]) swap(a[j],a[l]);
                if(costs[a[j]][a[l]] == INF){
                    uf1.merge(a[j],a[l]);
                    es.insert(Edge(c,a[j],a[l]));
                }else{
                    if(costs[a[j]][a[l]] < c) continue;
                    es.erase(Edge(costs[a[j]][a[l]],a[j],a[l]));
                    costs[a[j]][a[l]] = c;
                    es.insert(Edge(c,a[j],a[l]));
                }
            }
        }
    }
    if(uf1.size(0) != n){
        cout << -1 << endl;
        return 0;
    }
    dsu uf(n);
    ll ans = 0;
    for(auto e : es){
        if(!uf.same(e.a,e.b)){
            ans += e.cost;
            uf.merge(e.a,e.b);
        }
    }
    cout << ans << endl;
    return 0;
}