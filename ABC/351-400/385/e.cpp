#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int dist = 0;
    int k = -1;
    int a = -1,b = -1;
    auto dfs = [&](auto dfs, int v, int p=-1,int d=0)->void{
        if(d > dist){
            d = dist;
            k = v;
        }
        for(int u : g[v]){
            if(u == p) continue;
            dfs(dfs,u,v,d+1);
        }
    };
    dfs(dfs,0);
    a = k;
    dfs(dfs,a);
    b = k;
    int tyu = -1;
    auto f = [&](auto f, int v, int p=-1,int d= 0)->void{
        if(d == dist){
            tyu = v;
            return;
        }
        for(int u : g[v]){
            if(u == p) continue;
            f(f,u,v,d+1);
        }
    };
    f(f,b);
    vector<int> ds(n);
    ds[tyu] = 0;
    queue<int> q;
    q.push(tyu);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int u : g[v]){
            if(u == v) continue;
            if(ds[u] != 0) continue;
            q.push(u);
            ds[u] = ds[v]+1;
        }
    }
    int two = 1001001001;
    vector<int> x(n);
    auto f2 = [&](auto f2, int v, int p=-1)->int{
        int res = 0;
        for(int u : g[v]){
            if(u == p) continue;
            res += f2(f2,u,v);
        }
        return x[v] = res+1;
    };
    rep(i,n){
        if(ds[i] == 1){
            two = min(two,x[i]);
        } 
    }
    int ans = 0;
    rep(i,n){
        if(ds[i] == 1){
            ans += x[i] - two;
        }
    }
    cout << ans << endl;
    return 0;
}