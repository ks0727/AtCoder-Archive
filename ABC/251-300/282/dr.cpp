#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
using ll = long long;

ll nc2(int k){
    ll ans = (ll)k*(k-1)/2;
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >>v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool isbipartite = true;
    vector<int> color(n,-1);
    vector<int> unions(n,-1);
    auto dfs = [&](auto dfs, int v, int now, int uni)->void{
        unions[v] = uni;
        color[v] = now;
        for(int u : g[v]){
            if(color[u] != -1 && color[u] == color[v]){
                isbipartite = false;
                return;
            }
            if(color[u] == -1){
                dfs(dfs,u,1-now,uni);
            }
        }
    };
    int uni = 2;
    rep(i,n){
        if(color[i] == -1){
            dfs(dfs,i,0,uni);
            uni++; 
        }
    }
    if(!isbipartite){
        cout << 0 << endl;
        return 0;
    }
    map<P,int> mp;
    rep(i,n){
        mp[P(unions[i],color[i])]++;
    }
    ll ans = nc2(n) - (ll)m;
    for(auto [c,num] : mp){
        ans -= nc2(num);
    }
    cout << ans << endl;
    return 0;
}