#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

struct Edge{
    int to,x,y;
    Edge(int to=-1,int x=0,int y=0):to(to),x(x),y(y){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        a--;b--;
        g[a].emplace_back(Edge(b,x,y));
        g[b].emplace_back(Edge(a,-x,-y));

    }
    const ll INF = 1e18;
    vector<ll> x(n,INF),y(n,INF);
    x[0] = y[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto[u,dx,dy] : g[v]){
            if(x[u] != INF) continue;
            x[u] = x[v] + dx;
            y[u] = x[v] + dy;
            q.push(u);
        }
    }
    rep(i,n){
        if(x[i] == INF){
            cout << "undeciable" << endl;
        }
        else cout << x[i] << ' ' << y[i] << endl;
    }
    return 0;
}