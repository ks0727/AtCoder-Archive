#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    vector<int> dim(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        dim[a]++;
        dim[b]++;
    }
    vector<int> type(n);
    rep(i,n) if(dim[i] >= 4) type[i] = 2;
    rep(i,n){
        if(type[i] == 2){
            for(int u : g[i]){
                if(type[u] != 2) type[u] = 1;
            }
        }
    }
    //type:2 -> 周りに4つ以上持つ
    //type:1 -> 4つ以上持つ頂点の隣
    //type:0 -> 使われない
    int ans = 0;
    vector<bool> seen(n);
    rep(i,n){
        if(type[i] == 2 && !seen[i]){
            auto dfs = [&](auto dfs, int v, int p = -1)->int{
                if(type[v] != 2) return type[v];
                int res = 0;
                bool next = false;
                seen[v] = true;
                for(int u : g[v]){
                    if(type[u] == 2) next = true;
                }
                if(next){
                    int mx = 0;
                    for(int u : g[v]){
                        if(type[u] == 2){
                            mx = max(mx,dfs(dfs,u,v));
                        }
                    }
                    return mx+2+1;
                }else{
                    return 4;
                }
            };
            int now = dfs(dfs,i);
            ans = max(ans,now);
        }
    }
    cout << ans << endl;
    return 0;
}