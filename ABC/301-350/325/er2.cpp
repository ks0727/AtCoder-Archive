#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using T = tuple<ll,int,bool>;

int main(){
    int n; ll a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<ll> > d(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            ll x;
            cin >> x;
            d[i][j] = x;
        }
    }
    const ll INF = 1e18;
    vector<ll> ds(n,INF);
    ds[0] = 0;
    vector<bool> seen(n);
    priority_queue<T,vector<T>,greater<T> > q;
    q.emplace(0,0,false);
    ll ans = INF;
    while (!q.empty()){
        auto [cost,v,used] = q.top(); q.pop();
        seen[v] = true;
        if(ds[v] < cost) continue;
        rep(u,n){
            if(seen[u]) continue;
            if(used){
                if(cost+d[v][u]*b+c < ds[u]){
                    ds[u] = cost+d[v][u]*b+c;
                    q.emplace(cost+d[v][u]*b+c,u,true);
                }
            }else{
                if(cost+d[v][u]*a < ds[u]){
                    ds[u] = cost+d[v][u]*a;
                    q.emplace(cost+d[v][u]*a,u,false);
                }
                if(cost+d[v][u]*b+c<ds[u]){
                    ds[u] = cost+d[v][u]*b+c;
                    q.emplace(cost+d[v][u]*b+c,u,true);
                }
            }
        }
    }
    cout << ds[n-1] << endl;
    return 0;
}