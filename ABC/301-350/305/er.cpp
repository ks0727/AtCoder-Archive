#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > g(n);
    rep(i,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> hp(n,-1);
    priority_queue<P,vector<P>,less<P> > q;
    rep(i,k){
        int p,h;
        cin >> p >> h;
        p--;
        hp[p] = h;
        q.emplace(h,p);
    }
    while(!q.empty()){
        auto[h,v] = q.top(); q.pop();
        if(h != hp[v]) continue;
        for(int u : g[v]){
            if(hp[u] < h-1){
                hp[u] = h-1;
                q.emplace(hp[u],u);
            }
        }
    }
    vector<int> ans;
    rep(i,n) if(hp[i] >=0) ans.push_back(i+1);
    cout << ans.size() << endl;
    for(int x : ans) cout << x << ' '; cout << endl;
    return 0;
}