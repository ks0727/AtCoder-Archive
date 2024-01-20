#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    const int INF = 1001001001;
    vector dist(n,vector<int>(n,INF));
    queue<P> q;
    auto push = [&](int i,int j, int d){
        if(dist[i][j] == INF) return;
        dist[i][j] = d;
        q.emplace(i,j);
    };
    push(0,n-1,0);
    while(!q.empty()){
        auto [a,b] = q.front(); q.pop();
        int d = dist[a][b];
        for(int na : g[a]){
            for(int nb : g[b]){
                if(c[na] == c[nb]) continue;
                push(na,nb,d+1);
            }
        }
    }
    int ans = dist[n-1][0];
    if(ans == INF){
        ans = -1;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}