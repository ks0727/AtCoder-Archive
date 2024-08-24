#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vs(k);
    rep(i,k) cin >> vs[i],vs[i]--;
    vector<bool> connect(n);

    rep(i,k){
        if(i == 0) connect[vs[i]] = true;
        else{
            vector<bool> seen(n);
            seen[vs[i]] = true;
            vector<int> visited;
            auto dfs = [&](auto dfs, int v)->void{
                if(connect[v]){
                    for(int x : visited) connect[x] = true;
                    return;
                }
                seen[v] = true;
                visited.push_back(v);
                for(int u : g[v]){
                    if(seen[u]) continue;
                    dfs(dfs,u);
                    visited.pop_back();
                }
            };
            dfs(dfs,vs[i]);
        }
    }
    int ans = 0;
    rep(i,n) if(connect[i]) ans++;
    cout << ans << endl;
    return 0;
}