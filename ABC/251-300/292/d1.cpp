#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> seen(n);
    vector<int> uni(n);
    int unions = 0;
    auto dfs = [&](auto dfs,int v,int unions)->void{
        uni[v] = unions;
        seen[v] = true;
        for(auto u : g[v]){
            if(seen[u]) continue;
            dfs(dfs,u,unions);
        }
    };
    rep(i,n) if(!seen[i]){
        unions++;
        dfs(dfs,i,unions);
    }
    vector<int> ns(unions),es(unions);
    rep(i,n){
        int u = uni[i];
        u--;
        ns[u]++;
        es[u] += g[i].size();
    }
    rep(i,unions){
        if(ns[i] != es[i]/2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}