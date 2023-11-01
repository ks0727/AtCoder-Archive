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
    vector<int> edges;
    rep(i,n){
        if(g[i].size() == 1){
            edges.push_back(i);
        }
    }
    if(edges.size() == 0){
        cout << "No" << endl;
        return 0;
    }else{
        rep(i,edges.size()){
            queue<int> q;
            vector<bool> seen(n);
            q.push(edges[i]);
            seen[edges[i]] = true;
            bool ok = true;
            int cnt = 1;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(auto u : g[v]){
                    if(seen[u]) continue;
                    if(g[v].size() > 2){
                        ok = false;
                        break;
                    }
                    seen[u] = true;
                    q.push(u);
                    cnt++;
                }
            }
            if(ok && cnt == n){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}