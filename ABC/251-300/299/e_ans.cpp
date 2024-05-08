#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k; cin >> k;
    vector<int> p(k),d(k);    
    rep(i,k){
        cin >> p[i] >> d[i];
        p[i]--;
    }
    vector<vector<int> > to(n);
    const int INF = 1001001001;
    auto bfs = [&](int sv){
        vector<int> dist(n,INF);
        queue<int> q;
        q.push(sv); dist[sv] = 0;
        while (!q.empty())
        {
            int v = q.front(); q.pop();
            for(int u : g[v]){
                if(dist[u] != INF) continue;
                dist[u] = dist[v] +1;
                q.push(u);
            }
        }
        return dist;
    };
    rep(i,n) to[i] = bfs(i);
    string ans(n,'1');
    rep(i,k){
        rep(v,n){
            if(to[p[i]][v] < d[i]) ans[v] = '0';
        }
    }
    rep(i,k){
        int now = INF;
        rep(v,n){
            if(ans[v] == '1'){
                now = min(now,to[p[i]][v]);
            }
        }
        if(now != d[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}