#include <bits/stdc++.h>
using namespace  std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> st;
    rep(i,n) if(g[i].size() <= 1) st.insert(i);
    vector<bool> seen(n);
    auto dfs = [&](auto dfs, int v, int p)->bool{
        seen[v] = true;
        for(int u : g[v]){
            if(u == p) continue;
            if(seen[u]) return true;
            if(dfs(dfs,u,v)) return true;
        }
        return false;
    };
    int ans = 0;
    rep(i,n){
        if(!st.count(i)) continue;
        if(seen[i]) continue;
        if(dfs(dfs,i,-1)) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}