#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

struct Edge{
    int next;
    int cost;
    Edge(int next =0,int cost = 0) : next(next),cost(cost) {}
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        Edge e1,e2;
        e1.next = b; e2.next = a;
        e1.cost = c; e2.cost = c;
        g[a].push_back(e1);
        g[b].push_back(e2);
    }
    int ans = 0;
    auto dfs = [&](auto dfs,int v,vector<bool> visited, int dist)->void{
        visited[v] = true;
        ans = max(ans,dist);
        for(auto u : g[v]){
            if(visited[u.next]) continue;
            dfs(dfs,u.next,visited,dist+u.cost);
        }
    };
    rep(i,n) dfs(dfs,i,vector<bool>(n),0);
    cout << ans << endl;
    return 0;
}