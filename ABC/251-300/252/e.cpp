#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using T = tuple<ll,int,int>;
using P = tuple<ll,int>;

struct UnionFind{
    int n;
    vector<int> par,rank;
    UnionFind(int n):n(n),par(n,-1),rank(n){
        rep(i,n) par[i] = i;
    };
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void merge(int a, int b){
        int na = root(a); int nb = root(b);
        if(na == nb) return;
        if(rank[na] > rank[nb]) swap(na,nb);
        par[na] = nb;
        rank[nb] += rank[na];
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
};

int main(){
    int n,m;
    cin >> n>> m;
    vector<vector<T> > g(n);
    rep(i,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(c,b,i);
        g[b].emplace_back(c,a,i);
    }
    const ll INF = 1e18;
    vector<ll> dist(n,INF);
    dist[0] = 0;
    //sort(es.begin(),es.end());
    priority_queue<P,vector<P>, greater<P> > q;
    vector<int> ans(n);
    q.emplace(0,0);
    while(!q.empty()){
        auto [c,v] = q.top(); q.pop();
        if(dist[v] != c) continue;
        for(auto [cost,u,eid] : g[v]){
            if(dist[v] + cost < dist[u]){
                dist[u] = dist[v] + cost;
                q.emplace(dist[u],u);
                ans[u] = eid;
            }
        }
    }
    for(int i=1;i<n;i++) cout << ans[i]+1 << ' '; cout << endl;
    return 0;
}