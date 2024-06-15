#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(n-1);
    rep(i,n-1) cin >> p[i],p[i]--;
    vector<int> x(m),y(m);
    rep(i,m) cin >> x[i] >> y[i],x[i]--;
    vector<vector<int> > g(n);

    rep(i,n-1){
        g[p[i]].push_back(i+1);
    }
    vector<int> cover(n,-1);
    priority_queue<P,vector<P>> q;
    rep(i,m){
        if(cover[x[i]] < y[i]){
            cover[x[i]] = y[i];
            q.push(P(y[i],x[i]));
        }
    }
    while(!q.empty()){
        auto [c,v] = q.top(); q.pop();
        if(cover[v] != c) continue;
        for(int u : g[v]){
            if(cover[u] < c-1){
                cover[u] = c-1;
                q.emplace(c-1,u);
            }
        }
    }
    int ans = 0;
    rep(i,n) if(cover[i] >= 0) ans++;
    cout << ans << endl;
    return 0;
}