#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> seen(n);
    vector<int> visited;
    bool done = false;
    auto dfs = [&](auto dfs,int v)->void{
        if(!done) visited.push_back(v);
        seen[v] = true;
        if(v == y){
            done = true;
            return;
        }
        for(int u : g[v]){
            if(seen[u]) continue;
            dfs(dfs,u);
        }
        if(!done) visited.pop_back();
    };
    dfs(dfs,x);
    for(int x : visited) cout << x + 1 << ' ';
    cout << endl;
    return 0;
}