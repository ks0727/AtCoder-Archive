#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,bool>> > g(n);
    rep(i,m){
        int u,v,a;
        cin >> u >> v >> a;
        u--; v--;
        if(a == 1){
            g[u].push_back(make_pair(v,true));
            g[v].push_back(make_pair(u,true));
        }else{
            g[u].push_back(make_pair(v,false));
            g[v].push_back(make_pair(u,false));
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
    vector<bool> visited0(n),visited1(n);
    auto dfs = [&](auto dfs, int v, int now, bool on)->void{
        if(v == n-1){
            ans = min(ans,now);
            return;
        }
        if(on) visited1[v] = true;
        else visited0[v] = true;
        if(sch[v]){
            if(on){ //onの時はoffにする
                for(auto [u,o]:g[v]){
                    if(o) continue;
                    if(visited0[u]) continue;
                    dfs(dfs,u,now+1,false);
                    visited0[u] = false;
                }
            }else{ //offの時はonにする
                for(auto [u,o]:g[v]){
                    if(!o) continue;
                    if(visited1[u]) continue;
                    dfs(dfs,u,now+1,true);
                    visited1[u] = false;
                }
            }
        }else{
            for(auto [u,o] : g[v]){
                if(on){
                    if(!o) continue;
                    if(visited1[u]) continue;
                    dfs(dfs,u,now+1,true);
                    visited1[u] = false;
                }else{
                    if(o) continue;
                    if(visited0[u]) continue;
                    dfs(dfs,u,now+1,false);
                    visited0[u] = false;
                }
            }
        }
    };
    dfs(dfs,0,0,true);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}