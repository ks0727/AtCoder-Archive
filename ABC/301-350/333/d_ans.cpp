#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

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
    int ans = n;
    for(int v : g[0]){
        auto dfs = [&](auto dfs,int v, int p=-1)->int{
            int res = 1;
            for(int u : g[v]){
                if(u == p) continue;
                res += dfs(dfs,u,v);
            }
            cout << res << endl;
            return res;
        };
        int now = n - dfs(dfs,v,0);
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}