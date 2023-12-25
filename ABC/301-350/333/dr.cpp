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
    
    auto dfs = [&](auto dfs, int v, int p)->int{
        int res = 1;
        for(int u : g[v]){
            if(u == p) continue;
            res += dfs(dfs,u,v);
        }
        return res;
    };
    const int INF = 1e9;
    int ans = INF;
    for(int u : g[0]){
        ans = min(ans,n-dfs(dfs,u,0));
    }
    cout << ans << endl;
    return 0;
}