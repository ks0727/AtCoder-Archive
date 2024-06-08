#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n>> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    int k;
    cin >> k;
    vector<int> p(k),d(k);
    rep(i,k) cin >> p[i] >> d[i],p[i]--;
    vector<int> ans(n,-1);
    const int INF = 1e9;
    vector<vector<int> > path(n,vector<int>(n,INF));
    rep(i,n){
        queue<P> q;
        q.emplace(i,0);
        path[i][i] = 0;
        vector<bool> seen(n);
        while(!q.empty()){
            auto [v,dist] = q.front(); q.pop();
            seen[v] = true;
            for(int u : g[v]){
                if(seen[u]) continue;
                path[i][u] = min(path[i][u],dist+1);
                path[u][i] = min(path[u][i],dist+1);
                q.emplace(u,dist+1);
            }
        }
    }
    rep(i,k){
        int vs = p[i];
        queue<P> q;
        q.emplace(vs,0);
        vector<bool> visited(n);

        while(!q.empty()){
            auto[v,depth] = q.front(); q.pop();
            visited[v] = true;
            if(depth < d[i]) ans[v] = 0;
            for(int u : g[v]){
                if(visited[u]) continue;
                q.emplace(u,depth+1);
            }
        }
    }
    rep(i,n) if(ans[i]==-1) ans[i] = 1;
    string s = "";
    rep(i,n) s+= ans[i]+'0';
    rep(i,k){
        int v = p[i]; int dist = d[i];
        bool ok = false;
        rep(i,n){
            if(path[v][i] == dist && ans[i] == 1){
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << s << endl;
    return 0;
}