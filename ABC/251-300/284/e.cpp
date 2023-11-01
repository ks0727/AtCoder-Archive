#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

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
    int ans = 0;
    const int limit = 1000000;
    vector<bool> seen(n);
    auto dfs = [&](auto dfs,int v) ->void{
        seen[v] = true;
        if(ans == limit) return;
        ans++;
        for(auto u : g[v]){
            if(seen[u]) continue;
            dfs(dfs,u);
        }
        seen[v] = false;
    };
    dfs(dfs,0);
    cout << ans << endl;
    return 0;
}  