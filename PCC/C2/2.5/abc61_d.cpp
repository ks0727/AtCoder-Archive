#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using T = tuple<ll,int,int>;

struct UnionFind{
    int n;
    vector<int> par,rank;
    UnionFind(int n):n(n),par(n,-1),rank(n){
        rep(i,n) par[i] = i;
    }
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void merge(int a, int b){
        int la = root(a); int lb = root(b);
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
    rep(mi,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        es.emplace_back(-c,a,b);
    }
    const ll INF = 1e18;
    vector<ll> dist(n,INF);
    dist[0] = 0;
    rep(i,n){
        for(auto e : es){
            auto [c,a,b] = e;
            if(dist[a] == INF) continue;
            if(dist[a] + c < dist[b]){
                dist[b] = dist[a] + c;
                if(i == n-1){
                    cout << "inf" << endl;
                    return 0;
                } 
            }
        }
    }
    cout << -dist[n-1] << endl;
    return 0;
}