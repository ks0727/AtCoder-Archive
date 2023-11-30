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
    queue<int> leaf;
    rep(i,n) if(g[i].size() == 1) leaf.push(i);
    vector<bool> used(n);
    vector<int> ans;
    auto dfs = [&](auto dfs, int v)->void{
        used[v] = true;
        int p = g[v][0];
        if(used[p]) return;
        used[p] = true;
        ans.push_back(g[p].size());
        for(int u : g[p]){
            if(used[u]) continue;
            used[u] = true;
            for(int k : g[u]){
                if(used[k]) continue;
                if(g[k].size() == 1) continue;
                if(g[k][0] == u){
                    g[k][0] = g[k][1];
                    g[k].pop_back();
                }else{
                    g[k].pop_back();
                }
                dfs(dfs,k);
            }
        }
    };
    while(!leaf.empty()){
        dfs(dfs,leaf.front());
        leaf.pop();
    }
    sort(ans.begin(),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << ' ';
    }
    return 0;
}