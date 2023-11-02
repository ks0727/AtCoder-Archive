#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<int> > d(n,vector<int>(n));
    rep(i,n)rep(j,n){
        int dis;
        cin >> dis;
        d[i][j] = dis;
    }
    const ll INF = 1e18;
    ll ans = INF;
    auto dfs = [&](auto dfs, int v, vector<bool> seen,ll dist, int t, int happen)->void{
        seen[v] = true;
        if(v == n-1){
            ans = min(ans,dist);
            return;
        }
        rep(u,n){
            if(seen[u]) continue;
            if(t >= happen) dist +=  (ll)u*b+c;
            else dist += u*a;
            t++;
            dfs(dfs,u,seen,dist,t,happen);
        }
    };
    rep(i,n) dfs(dfs,0,vector<bool>(n),0,0,i);
    cout << ans << endl;
    return 0;
}