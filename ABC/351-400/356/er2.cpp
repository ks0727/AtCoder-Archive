#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i],a[i]--;
    vector<int> visited(n,-1);
    vector<bool> finished(n);
    vector<vector<int> > g(n);
    rep(i,n) g[i].push_back(a[i]);

    int ans = 0;
    auto dfs = [&](auto dfs,int v, int depth)->void{
        visited[v] = depth;
        for(int u : g[v]){
            if(finished[v]) continue;
            if(visited[u] != -1 && !finished[u]){
                ans += depth - visited[u]+1;
                return;
            }
            dfs(dfs,u,depth+1);
            //visited[u] = -1;
            //finished[u] = false;
        }
        finished[v] = true;
        return;
    };
    
    rep(i,n) if(visited[i] == -1) dfs(dfs,i,0);
    //rep(i,n) cout << visited[i] << ' '; cout << endl;
    cout << ans << endl;
    return 0;
}