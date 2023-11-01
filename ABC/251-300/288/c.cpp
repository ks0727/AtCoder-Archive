#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >>m;
    vector<set<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    vector<bool> seen(n);
    int ans = 0;
    auto dfs = [&](auto dfs, int v) ->void{
        for(auto u : g[v]){
            if(seen[u]){
                ans++;
                continue;
            }
            seen[u] = true;
            dfs(dfs,u);
        }
    };
    dfs(dfs,0);
    cout << ans << endl;
    return 0;
}