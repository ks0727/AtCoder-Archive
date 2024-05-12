#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

struct Edge{
    int to,cost;
    Edge(int to=-1,int cost=0):to(to),cost(cost){}
};
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};

int main(){
    int n;
    cin >> n;
    vector<string> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<Edge> > g(n*n);
    auto toid = [&](int i,int j){
        return i*n+j;
    };
    auto tops = [&](int id){
        return P(id/n,id%n);
    };
    rep(i,n){
        rep(j,n){
            rep(d,2){ //右と下にだけ辺を繋いでいく
                int ni = i+di[d]; int nj = j+dj[d];
                if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                int id1 = toid(i,j);
                int id2 = toid(ni,nj);
                if(c[i][j] == c[ni][nj]){ //同じ色の時はコスト0
                    g[id1].push_back(Edge(id2,0));
                    g[id2].push_back(Edge(id1,0));
                }else{ //違う色の時はコスト1にする
                    g[id1].push_back(Edge(id2,1));
                    g[id2].push_back(Edge(id1,1));
                }
            }
        }
    }
    const int INF = 1001001001;
    auto dijkstra = [&](const vector<vector<Edge> >&g,vector<int>& dist,int start, int end,char now){
        priority_queue<P,vector<P>,greater<P> > q;
        dist[start] = 0;
        q.emplace(0,start);
        while(!q.empty()){
            auto [d,v] = q.top(); q.pop();
            if(dist[v] < d) continue;
            for(auto &e : g[v]){
                auto [ni,nj] = tops(e.to);
                int nd = 0;
                if(c[ni][nj] == now){
                    nd = dist[v];
                }else{
                    nd = dist[v]+1;
                }
                if(nd < dist[e.to]){
                    dist[e.to] = nd;
                    q.emplace(nd,e.to);
                }
            }
        }
        return dist[end];
    };
    vector<int> dist1(n*n,INF);
    vector<int> dist2(n*n,INF);
    int ans = dijkstra(g,dist1,0,n*n-1,'R');
    ans += dijkstra(g,dist2,n-1,n*n-n,'B');
    cout << ans << endl;
    return 0;
}