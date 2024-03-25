#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

void solve(){
    int n,m;
    cin>> n >> m;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<P> q;
    q.emplace(0,n-1);
    const int INF = 1001001001;
    vector<vector<int> > dist(n,vector<int>(n,INF));
    dist[0][n-1] = 0; 
    while(!q.empty()){
        auto [ao,ta] = q.front(); q.pop();
        if(ao == n-1 && ta == 0) break;
        for(int nao : g[ao]){
            for(int nta : g[ta]){
                P next = P(nao,nta);
                if(c[nao] == c[nta]) continue;
                if(dist[nao][nta] != INF) continue; //訪れていたらcontinue
                dist[nao][nta] = dist[ao][ta] + 1;
                q.emplace(next);
            }
        }
    }
    if(dist[n-1][0] != INF) cout << dist[n-1][0] << endl;
    else cout << -1 << endl;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}