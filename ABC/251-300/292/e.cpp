#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int main(){
    int n,m;
    cin >> n >> m;
    vector<set<int> > g1(n),g2(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        --u; --v;
        g1[u].insert(v);
        g2[v].insert(u);
    }
    queue<P> q;
    auto dfs = [&](auto dfs, int v, int depth = 0,int p = -1, int pp = -1)->void{
        if(depth == 0){
            pp = v;
        }
        if(depth == 2){
            if(pp != -1 && !g1[pp].count(v)){
                q.emplace(pp,v);
                return;
            }
        }
        for(int u : g1[v]){
            if(u == p) continue;
            dfs(dfs,u,depth+1,v,pp);
        }
    };
    rep(i,n) dfs(dfs,i);
    int ans = 0;
    while(!q.empty()){
        auto [a,b] = q.front(); q.pop();
        g1[a].insert(b);
        g2[b].insert(a);
        //cout << a << ' ' << b << endl;
        ans++;
        for(int x : g2[a]){
            if(x != b && !g1[x].count(b)){
                q.emplace(x,b);
            }
        }
    }
    cout << ans << endl;
    return 0;
}