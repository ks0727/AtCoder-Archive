#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int> > g(n);
    rep(i,n) cin >> a[i];
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    vector<bool> visited(n);
    auto dfs = [&](auto dfs, int v, int p)->void{
        if(v == n-1){
            ans = max(ans,p);
            return;
        }
        visited[v] = true;
        for(int u : g[v]){
            if(visited[u]) continue;
            if(a[v] >= a[u]) continue;
            dfs(dfs,u,p+1);
        }
        visited[v] = false;
    };
    dfs(dfs,0,0);
    if(ans != 0) cout << ans+1 << endl;
    else cout << ans << endl;
    return 0;
}