#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;
struct Edge{
    int to; ll cost;
    Edge(int to,ll cost):to(to),cost(cost){}
};
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
    vector<bool> seen(n);
    const ll INF = 1e18;
    priority_queue<P,vector<P>,greater<P> > q;
    vector<ll> distance(n,INF);
    distance[0] = 0;
    q.emplace(distance[0],0);
    while(!q.empty()){
        ll dis = q.top().first;
        int from = q.top().second;
        q.pop();
        if(distance[from] < dis) continue;
        for(auto& e : g[from]){
            ll nd = distance[from]+e.cost;
            if(nd < distance[e.to]) q.emplace(distance[e.to]=nd,e.to);
        }
    }
    cout << distance[n-1] << endl;
    return 0;
}