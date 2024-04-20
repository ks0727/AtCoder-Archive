#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using ll = long long;

ll c2(int x){
    return (ll)x*(x-1)/2;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<P> es;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        es.emplace_back(a,b);
    }
    vector<int> visited(n,-1);
    int uni = 0;
    auto dfs = [&](auto dfs, int v, int uni)->void{ 
        visited[v] = uni;
        for(int u : g[v]){
            if(visited[u] != -1) continue;
            dfs(dfs,u,uni);
        }
    };
    rep(i,n){
        if(visited[i] == -1){
            dfs(dfs,i,uni);
            uni++;
        }
    }
    ll ans = 0;
    vector<int> vs(uni);
    vector<int> ues(uni);
    rep(i,m) ues[visited[es[i].first]]++;
    rep(i,n) vs[visited[i]]++;
    rep(i,uni){
        ans += c2(vs[i]);
        ans -= ues[i];
    }
    cout << ans << endl;
    return 0;
}