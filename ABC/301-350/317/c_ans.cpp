#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
//Nが小さいから全探索する

struct Edge{
    int to,cost;
    Edge(int to =0,int cost = 0) : to(to),cost(cost) {}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    int ans = 0;
    auto f = [&](auto f, int v, vector<bool> visited, int dist) -> void{
        visited[v] = true;
        ans = max(ans,dist);
        for(auto e: g[v]){
            if(visited[e.to]) continue;
            f(f,e.to,visited,dist+e.cost);
        }
    };
    rep(i,n) f(f,i,vector<bool>(n),0);
    cout << ans << endl;
    return 0;
}