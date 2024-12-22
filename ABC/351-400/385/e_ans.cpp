#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dim(n);
    rep(i,n) dim[i] = g[i].size();

    int ans = n;
    rep(v,n){
        vector<int> d;
        for(int u : g[v]) d.push_back(dim[u]);
        sort(dim.rbegin(),dim.rend());
        rep(i,dim[v]){
            int now = d[i]*(i+1) + 1; //ゆきに含まれる頂点のかず
            ans = min(ans,n-now);
        }
    }
    cout << ans << endl;
    return 0;
}