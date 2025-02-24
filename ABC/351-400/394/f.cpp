#include <bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<int> dim(n);
    vector<vector<int> > g(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        dim[a]++;
        dim[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,n){
        if(dim[i] >= 4) break;
        if(i == n-1){
            cout << -1 << endl;
            return 0;
        }
    }
    //以下次数が4以上の頂点が最低1つ存在
    vector<bool> sub(n);
    rep(i,n){
        if(dim[i] < 4) continue;
        for(int u : g[i]){
            if(dim[u] < 4) sub[u] = true;
        }
    }
    set<int> leaves;
    vector<int> ddim(n);
    //次数が4以上かつ次数4以上の頂点と繋がっている次数が1のところを探す
    rep(i,n){
        if(dim[i] < 4) continue;
        for(int u : g[i]){
            if(dim[u] < 4) continue;
            ddim[u]++;
            ddim[i]++;
        }
    }
    rep(i,n) if(ddim[i] == 2) leaves.insert(i);
    if(leaves.size() == 0){ //孤立して存在している
        cout << 5 << endl;
        return 0;
    }
    //以下次数が4以上通しでかつ繋がっているところが存在している
    dsu uf(n);
    int ans = -1;
    vector<bool> seen(n);
    for(int i : leaves){
        if(seen[i]) continue;
        seen[i] = true;
        auto dfs = [&](auto dfs, int v, int p=-1)->int{
            if(!seen[v] && leaves.count(v)){
                seen[v] = true;
                return 1;
            }
            int res = 0;
            for(int u : g[v]){
                if(u == p) continue;
                if(dim[u] < 4) continue;
                res = max(res,dfs(dfs,u,v)+1);
            }
            return res;
        };
        ans = max(ans,dfs(dfs,i));
    }
    cout << 3*ans+2 << endl;
    return 0;
}