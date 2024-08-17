#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using P = pair<ll,int>;
using T = tuple<ll,int,int>;
struct UnionFind{
    int n;
    vector<int> par,rank;
    UnionFind(int n):n(n),par(n,-1),rank(n,0){
        rep(i,n) par[i] = i;
    }
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void merge(int a, int b){
        int la = root(a);
        int lb = root(b);
        if(la == lb) return;
        if(rank[la] > rank[lb]) swap(la,lb);
        par[la] = lb;
        rank[lb] += rank[la];
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<T> es;
    vector<vector<P> > g(n);
    rep(mi,m){
        int s,d; ll c;
        cin >> s >> d >> c;
        s--; d--;
        g[s].emplace_back(c,d);
        g[d].emplace_back(c,s);
        es.emplace_back(c,s,d);
    }
    sort(es.begin(),es.end());
    const ll INF = 1e18;
    vector<ll> costs(n,INF);
    UnionFind uf(n);
    ll ans = 0;
    int num = 0;
    for(auto e: es){
        auto [c,v,u] = e;
        if(!uf.same(u,v)){
            uf.merge(u,v);
            costs[u] = min(c,costs[u]);
            costs[v] = min(c,costs[u]);
            ans += c;
        }else{
            auto dfs = [&](auto dfs, int v){

            };
        }
    }
    cout << num << ' ' << ans << endl;
    return 0;
}