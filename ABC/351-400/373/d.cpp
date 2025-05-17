#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using P = pair<ll,int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> dim(n);
    vector<vector<P> > g(n);
    const ll INF = 1e18;
    rep(i,m){
        int a,b; ll w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].emplace_back(w,b);
        g[b].emplace_back(-w,a);
        //cost[a][b] = w;
        dim[b]++;
    }
    queue<int> q;
    rep(i,n) if(dim[i] == 0) q.emplace(i);
    vector<int> vs;
    while(!q.empty()){
        int v = q.front();q.pop();
        vs.push_back(v);
        for(auto [w,u] : g[v]){
            dim[u]--;
            if(dim[u] == 0) q.push(u);
        }
    }
    
    vector<ll> ans(n,INF);
    rep(i,n){
        if(ans[i] != INF) continue;
        ans[i] = 0;
        auto dfs = [&](auto dfs, int v)->void{
            for(auto [w,u] : g[v]){
                if(ans[u] != INF) continue;
                ans[u] = ans[v] + w;
                dfs(dfs,u);
            }
        };
        dfs(dfs,i);
    }
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}
