#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<set<int> > g(n);
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    
    auto isEgde = [&](int v,auto g){
        if(g[v].size() == 1) return true;
        else return false;
    };

    vector<int> ans;
    set<int> centers;
    vector<bool> visited(n);
    bool isdone = false;
    while(true){
        rep(i,n){
            if(!visited[i]) break;
            if(i == n-1) isdone = true; 
        }
        if(isdone) break;
        rep(i,g.size()){
        if(isEgde(i,g)){
            centers.insert(*g[i].begin());
        }
        while(!centers.empty()){
            int center = *centers.begin();
            visited[center] = true;
            centers.erase(center);
            int level = 0;
            vector<int> egdes;
            for(int v : g[center]){
                if(visited[v]) continue;
                visited[v] = true;
                g[v].clear();
                level++;
                egdes.push_back(v);
            }
            g[center].clear();
            ans.push_back(level);
            for(int u : egdes){
                rep(i,g.size()){
                    if(g[i].count(u)) g[i].erase(u);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    rep(i,ans.size()) cout << ans[i] << ' ';
    cout << endl;
    return 0;
    }
    
}