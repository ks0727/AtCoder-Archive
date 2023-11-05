#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<vector<int> > g(n);
    rep(i,m){
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }
    vector<int> x(n,-1);
    bool bipartite = true;
    auto dfs = [&](auto dfs, int v, int xval)->void{
        x[v] = xval;
        for(auto u : g[v]){
            if(x[u] == -1){
                dfs(dfs,u,1-xval);
            }
            else if(x[u] == x[v]){
                bipartite = false;
            }
        }
    };
    rep(i,n){
        if(x[i] == -1) dfs(dfs,i,0);
    }
    cout << (bipartite ? "Yes" : "No") << endl;
    return 0;
}