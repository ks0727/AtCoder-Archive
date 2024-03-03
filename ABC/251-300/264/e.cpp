#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,e;
    cin >> n >> m >> e;
    vector<P> es;
    vector<set<int> > g(n+m);
    rep(i,e){
        int u,v;
        cin >> u >> v;
        u--; v--;
        es.emplace_back(u,v);
        g[u].insert(v);
        g[v].insert(u);
    }
    int q;
    cin >> q;
    int ans = n;
    rep(qi,q){
        int x;
        cin >> x;
        x--;
        auto [da,db] = es[x];
        if(da > db) swap(da,db);
        g[da].erase(db);
        g[db].erase(da);
        if(da >= n){
            cout << ans << endl;
            continue;
        }
        vector<bool> visited(n+m);
        vector<int> seen;
        auto dfs = [&](auto dfs, int v)->bool{
            if(v >= n) return true;
            visited[v] = true;
            if(v < n) seen.push_back(v);
            for(int u : g[v]){
                if(visited[u]) continue;
                if(dfs(dfs,u)) return true;
                visited[v] = false;
            }
            return false;
        };
        if(!dfs(dfs,da)) ans -= seen.size();   
        cout << ans << endl;
    }   
    return 0;
}