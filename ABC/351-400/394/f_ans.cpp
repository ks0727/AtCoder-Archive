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
    int ans = -1;
    auto dfs = [&](auto dfs, int v,int p=-1)->int{
        vector<int> d;
        int res = 1;
        for(int u : g[v]){
            if(u == p) continue;
            d.push_back(dfs(dfs,u,v));
        }
        sort(d.rbegin(),d.rend());
        if(d.size() >= 3){ //3以上あるならば今いる頂点vから遷移可能
            res = d[0]+d[1]+d[2] + 1;
            if(d.size() >= 4) ans = max(ans,res+d[3]);
        }
        if(d.size() == 1){ //子が1個以上ある場合
            if(d[0]+1 > 2) ans = max(ans,d[0]+1);
        }
        return res;
    };
    dfs(dfs,0);
    cout << ans << endl;
    return 0;
}