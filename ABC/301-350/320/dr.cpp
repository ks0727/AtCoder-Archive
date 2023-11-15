#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

struct Edge{
    int next,rx,ry;
    Edge(int next = -1,int rx = 0, int ry = 0):next(next),rx(rx),ry(ry){}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<Edge> > g(n);
    rep(i,m){
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        a--; b--;
        if(a > b){
            swap(a,b);
            g[a].push_back(Edge(b,-x,-y));
            g[b].push_back(Edge(a,x,y));
        }else{
            g[a].push_back(Edge(b,x,y));
            g[b].push_back(Edge(a,-x,-y));
        }
    }
    const ll INF = 1e18;
    vector<P> ps(n,P(INF,INF));
    ps[0] = P(0,0);
    auto dfs = [&](auto dfs, int v, P pos)->void{
        for(auto u : g[v]){
            if(ps[u.next] != P(INF,INF)) continue;
            ps[u.next] = P(pos.first+u.rx,pos.second+u.ry);
            dfs(dfs,u.next,ps[u.next]);
        }
    };
    dfs(dfs,0,ps[0]);
    rep(i,n){
        if(ps[i] == P(INF,INF)) cout << "undecidable" << endl;
        else cout << ps[i].first << ' ' << ps[i].second << endl; 
    }
    return 0;
}