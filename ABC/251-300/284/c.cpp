#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> seen(n);
    int ans = 0;
    rep(i,n){
        queue<int> q;
        if(!seen[i]){
            q.push(i);
            seen[i] = true; 
            ans++;
        }
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto u : g[v]){
                if(seen[u]) continue;
                seen[u] = true;
                q.push(u);
            }
        }
    }
    cout << ans << endl;
    return 0;
}