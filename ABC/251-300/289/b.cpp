#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<int> a;
    rep(i,m){
        int ver;
        cin >> ver;
        ver--;
        g[ver].push_back(ver+1);
        g[ver+1].push_back(ver);
        a.push_back(ver);
    }
    vector<int> ans;
    vector<bool> seen(n);
    auto dfs = [&](auto dfs, int v)->void{
        seen[v] = true;
        for(auto u : g[v]){
            if(seen[u]) continue;
            dfs(dfs,u);
        }
        ans.push_back(v+1); 
    };
    rep(i,n){
        if(!seen[i]) dfs(dfs,i);
    }
    rep(i,ans.size()) cout << ans[i]<< ' ';
    return 0;
}