#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    rep(i,n){
        int c;cin >> c;
        rep(ci,c){
            int p;
            cin >> p; p--;
            g[i].push_back(p);
        }
    }
    vector<int> visited(n);
    vector<int> ans;
    auto dfs = [&](auto dfs, int v)->void{
        visited[v] = true;
        for(auto u : g[v]){
            if(visited[u]) continue;
            dfs(dfs,u);
        }
        ans.push_back(v);
    };
    dfs(dfs,0);
    ans.pop_back();
    for(auto x : ans) cout << x+1 << ' '; cout << endl;
    return 0;
}