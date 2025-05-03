#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const int INF = n;
    vector<int> min_adj(n, INF);
    for (int j = 1; j < n; j++){
        for (int u : g[j]){
            if(u < j){
                min_adj[j] = min(min_adj[j], u);
            }
        }
    }

    vector<int> diff(n+2, 0);
    for (int j = 1; j < n; j++){
        if(min_adj[j] < INF && min_adj[j] + 1 <= j){
            int L = min_adj[j] + 1;
            int R = j;
            diff[L] += 1;
            diff[R+1] -= 1;
        }
    }

    vector<int> f(n+1, 0);
    for (int k = 1; k <= n; k++){
        f[k] = f[k-1] + diff[k];
    }

    dsu d(n);
    vector<int> ans(n+1, 0);
    ans[1] = f[1];

    for (int k = 2; k <= n; k++){
        int cur = k - 1;
        for (int u : g[cur]){
            if(u < cur){
                d.merge(u, cur);
            }
        }
        if(d.size(0) != k) {
            ans[k] = -1;
        } else {
            ans[k] = f[k];
        }
    }

    for (int k = 1; k <= n; k++){
        cout << ans[k] << "\n";
    }

    return 0;
}

