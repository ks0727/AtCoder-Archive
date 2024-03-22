#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > g0(n),g1(n);
    rep(i,m){
        int u,v,a;
        cin >> u >> v >> a;
        u--; v--;
        if(a==0){
            g0[u].push_back(v);
            g0[v].push_back(u);
        }else{
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
    }
    vector<bool> sch(n);
    rep(i,k){
        int s;
        cin >> s; s--;
        sch[s] = true;
    }
    const int INF = 1001001001;
    int ans = INF;
    vector<int> dist0(n,INF),dist1(n,INF);
    dist0[0] = dist1[0] = 0;
    priority_queue<P,vector<P>,greater<P> > q;
    q.emplace(0,0);
    while (!q.empty()){
        auto [v,cost] = q.top(); q.pop();
        if(dist0[v] != cost) continue;
    }
    
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}