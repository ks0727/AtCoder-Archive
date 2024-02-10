#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int to; ll cost;
    Edge(int to, ll cost) : to(to),cost(cost){}
};
// dfsでは最小コストを求めることはできない
int main(){
    int n;
    cin >> n;
    vector<vector<Edge> > g(n);
    rep(i,n-1){
        ll a,b; int x;
        cin >> a >> b >> x;
        x--;
        g[i].emplace_back(i+1,a);
        g[i].emplace_back(x,b);
    }
    const ll INF = 1e18;
    ll ans = INF;
    auto dfs = [&](auto dfs,int v, ll c,vector<bool> seen)->void{
        if(v == n-1){
            ans = min(ans,c);
            return;
        }
        seen[v] = true;
        for(auto u : g[v]){
            if(seen[u.to]) continue;
            dfs(dfs,u.to,u.cost+c,seen);
        }
    };
    dfs(dfs,0,0,vector<bool>(n));
    cout << ans << endl;
    return 0;
}