#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

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
    ll ans = INF;
    vector<bool> seen(n);
    vector<int> visited;
    auto dfs = [&](auto dfs,int v, ll cur, bool train)->void{
        if(v == n-1){
            ans = min(ans,cur);
            return;
        }
        seen[v] = true;
        visited.push_back(v);
        rep(u,n){
            if(seen[u]) continue;
            if(train){
                dfs(dfs,u,cur+d[v][u]*b+c,true); //すでに電車を使っていたら次も電車しか使えない
                seen[u] = false;
            }
            else{
                dfs(dfs,u,cur+d[v][u]*a,false); //車を乗った時
                seen[u] = false;
                dfs(dfs,u,cur+d[v][u]*b+c,true); //電車を使った時
                seen[u] = false;
            }
        }
        seen[v] = false;
        visited.pop_back();
    };
    dfs(dfs,0,0,false);
    cout << ans << endl;
    return 0;
}