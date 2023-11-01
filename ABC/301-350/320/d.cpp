#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<bool> decided(n);
    decided[0] = true;
    ll const INF = 1e18;
    vector<vector<P> > g(n,vector<P>(n));
    vector<P> ans(n,{INF,INF});
    ans[0] = {0,0};
    rep(i,m){
        int a,b;
        ll x,y;
        cin >> a >> b >> x >>y;
        g[a][b] = {x,y};
        g[b][a] = {-x,-y};
    }
    auto f = [&](auto f, int v)-> void{
        decided[v] = true;
        for(auto p : g[v]){
            if(decided[p.first]){
                
            }
        }
    };
}
