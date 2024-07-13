#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using mint = modint998244353;

struct Edge{
    int to,cost;
    Edge(int to=-1,int cost =0):to(to),cost(cost){}
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans(n);
    ans[0] = n; ans[1] = n*(n-1)/2;
    vector<vector<Edge> > g(n);
    rep(i,n){
        for(int j=i+1;j<n;++j){
            g[i].emplace_back(j,a[j]-a[i]);
        }
    }
    auto dfs = [&](auto dfs,int v,int depth,int diff)->void{
        int add = 0;
        for(auto e: g[v]){
            assert(e.to != -1);
            if(depth != 0){
                if(e.cost != diff) continue;
                dfs(dfs,e.to,depth+1,diff);
                add++;
            }else{
                dfs(dfs,e.to,depth+1,a[e.to]-a[v]);
                add++;
            }
        }
        if(add == 0){
            for(int di=2;di<depth+1;di++) ans[di]+= depth-di+1;
        }
        return;
    };
    dfs(dfs,0,0,0);
    rep(i,n) cout << ans[i] << ' '; cout << endl;
    return 0;
}