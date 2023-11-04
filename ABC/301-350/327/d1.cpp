#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    vector<vector<int> > g(n);
    rep(i,m) cin >> a[i];
    rep(i,m) cin >> b[i];
    rep(i,m){
        if(a[i] == b[i]){
            cout << "No" << endl;
            return 0;
        }
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }
    vector<int> seen(n,-1);
    bool ok = true;
    auto dfs = [&](auto dfs, int v, int prev)->void{
        if(prev){
            seen[v] = 0;
            prev = 0;
        }
        else{
            seen[v] = 1;
            prev = 1;
        }
        for(auto u : g[v]){
            if(seen[u] != -1 && seen[u] == seen[v]){
                ok = false;
                return;
            }
            if(seen[u] != -1 && seen[u] != seen[v]) continue;
            dfs(dfs,u,prev);
        }
    };
    dfs(dfs,0,1);
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}