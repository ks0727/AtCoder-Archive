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
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> covered(n);
    rep(i,k){
        int p,h; 
        cin >> p >> h;
        p--;
        queue<P> q;
        q.push(P(p,h));
        while(!q.empty()){
            auto [v,h] = q.front(); q.pop();
            if(h < 0) continue;
            covered[v] = true;
            for(int u : g[v]){
                q.push(P(u,h-1));
            }
        }
    }
    int ans = 0;
    vector<int> defended;
    rep(i,n){
        if(covered[i]){
            ans++;
            defended.push_back(i+1);
        } 
    }
    cout << ans << endl;
    for(int x : defended) cout << x << ' '; cout << endl;
    return 0;
}