#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    const int INF = 1e9;
    int ans = INF;
    vector<bool> seen(n);
    auto dfs = [&](auto dfs,int v, int cost)->void{
        seen[v] = true;
        for(int u :g[v]){
            if(seen[u]) continue;
            if(v == 0) dfs(dfs,u,0);
            else dfs(dfs,u,cost+g[v].size());
        }
        ans = min(ans,cost);
    };
    dfs(dfs,0,0);
    cout << ans + 1 << endl;
    return 0;
}