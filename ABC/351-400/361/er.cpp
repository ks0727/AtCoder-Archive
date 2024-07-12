#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

struct Edge{
    int a; ll cost;
    Edge(int a,ll cost):a(a),cost(cost){}
};

int main(){
    int n;
    cin >> n;
    vector<vector<Edge> > g(n);
    ll ans = 0;
    rep(i,n-1){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
        ans += c;
    }
    set<int> es;
    rep(i,n) if(g[i].size() == 1) es.insert(i);
    int e1 = -1,e2 = -1;
    ll dia = 0;
    auto dfs = [&](auto dfs, int v,int p = -1, ll d=0,bool first=true)->void{
        if(g[v].size() == 1 && p != -1){
            if(dia < d){
                dia = d;
                if(first) e1 = v;
                else e2 = v;
            }
            return;
        }
        for(auto e: g[v]){
            auto [u,c] = e;
            if(u == p) continue;
            dfs(dfs,u,v,d+c,first);
        }
    };
    dfs(dfs,0,-1,0,true);
    dfs(dfs,e1,-1,0,false);
    ans *= 2;
    cout << ans-dia << endl;
    return 0;
}