#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    vector<int> dim(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    ll ans = 0;
    rep(i,n){
        queue<int> q;
        q.push(i);
        set<int> visit;
        while(!q.empty()){
            int v = q.front(); q.pop();
            visit.insert(v);
            //cout << v << endl;
            for(int u : g[v]){
                if(visit.count(u)) continue;
                q.push(u);
            }
        }

        ans += visit.size()-1-g[i].size();
    }
    cout << ans << endl;
    return 0;
}