#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i];
    rep(i,m) cin >> b[i];
    bool bipartite = true;
    vector<vector<int> > g(n);
    rep(i,m){
        if(a[i] == b[i]){
            cout << "No" << endl;
            return 0;
        }
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }
    vector<int> value(n,-1);
    auto dfs = [&](auto dfs,int v,int zo)->void{
        value[v] = zo;
        for(auto u : g[v]){
            if(value[u] != -1 && value[v] != value[u]) continue;
            if(value[u] != -1 && value[v] == value[u]){
                bipartite = false;
                return;
            }
            else{
                dfs(dfs,u,1-zo);
            }
        }
    };
    rep(i,n){
        if(value[i] == -1) dfs(dfs,i,0);
    }
    if(bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}