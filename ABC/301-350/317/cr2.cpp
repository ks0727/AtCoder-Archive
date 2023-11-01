#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Edge{
    int next,cost;
    Edge(int next = -1,int cost = -1) : next(next),cost(cost) {}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(Edge(b,c));
        g[b].push_back(Edge(a,c));
    }
    int ans = 0;
    auto dfs = [&](auto dfs, int v, vector<bool> visited, int dist) -> void{
        ans = max(ans,dist);
        visited[v] = true;
        for(auto u : g[v]){
            if(visited[u.next]) continue;
            dfs(dfs,u.next,visited,dist+u.cost);
            cout << dist << endl;
        }
    };
    rep(i,n) dfs(dfs,i,vector<bool>(n),0);
    cout << ans << endl;
    return 0;
}