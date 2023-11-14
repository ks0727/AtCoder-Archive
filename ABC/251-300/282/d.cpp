#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    dsu uf(n);
    vector<set<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
        uf.merge(u,v);
    }
    vector<int> seen(n,-1);
    bool isdone = false;
    auto dfs = [&](auto dfs, int v, int value)->void{
        seen[v] = value;
        for(auto u : g[v]){
            if(seen[u] != -1 && seen[u] == seen[v]){
                cout << 0 << endl;
                isdone = true;
                exit(0);
            }
            if(seen[u] == -1) dfs(dfs,u,1-value);
        }
    };
    if(isdone) return 0;
    rep(i,n) if(seen[i] == -1) dfs(dfs,i,0);
    int ans = 0;
    rep(i,n){
        for(int j = i+1;j<(n);j++){
            if(g[i].count(j)) continue;
            if(!uf.same(i,j)) continue;
            if(seen[i] != seen[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}