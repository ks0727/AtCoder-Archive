#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin  >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> d(n,-1);
    priority_queue<P> q;
    rep(i,k){
        int p,h;
        cin >> p >> h;
        p--;
        d[p] = h;
        q.emplace(h,p);
    }
    while(!q.empty()){
        auto [h,v] =q.top(); q.pop();
        if(d[v] != h) continue;
        for(int u : g[v]){
            if(d[u] >= h-1) continue;
            d[u] = h-1;
            q.emplace(h-1,u);
        }
    }
    vector<int> ans;
    rep(i,n) if(d[i]>=0) ans.push_back(i+1);
    cout << ans.size() << endl;
    for(int v : ans) cout << v << ' '; cout << endl;
    return 0;
}