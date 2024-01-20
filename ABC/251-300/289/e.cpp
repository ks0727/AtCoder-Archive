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
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<P,int> mp;
    queue<P> q;
    q.emplace(0,n-1);
    mp[q.front()] = 0;
    int ans = -1;
    while(!q.empty()){
        auto [a,b] = q.front(); q.pop();
        for(int na : g[a]){
            for(int nb : g[b]){
                if(na == a) continue;
                if(nb == b) continue;
                if(c[na] == c[nb]) continue;
                q.emplace(na,nb);
                mp[P(na,nb)] = mp[P(a,b)] + 1;
                if(na == n-1 && nb == 0) ans = mp[P(na,nb)];
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    rep(ti,t){
        solve();
    }
    return 0;
}