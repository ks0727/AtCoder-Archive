#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int> > g(n);
    vector<int> indeg(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    rep(i,n){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vector<int> sorted_vs;
    while(!q.empty()){
        if(q.size() != 1){
            cout << "No" << endl;
            return 0;
        }
        int v = q.front(); q.pop();
        sorted_vs.push_back(v);
        for(int u : g[v]){
            indeg[u]--;
            if(indeg[u] == 0) q.push(u);
        }
    }
    if(sorted_vs.size() != n){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> ans(n);
    rep(i,n) ans[sorted_vs[i]] = i+1;
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}