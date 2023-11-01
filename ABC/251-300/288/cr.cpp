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
    vector<bool> seen(n);
    int unis = 0;
    rep(i,n){
        queue<int> q;
        if(!seen[i]){
            q.push(i);
            unis++;
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
    cout << m - n + unis << endl;
    return 0;
}