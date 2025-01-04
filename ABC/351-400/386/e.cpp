#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    auto dfs = [&](auto dfs, int used = 0, int depth = 0,ll now=0)->void{
        if(used == k){
            ans = max(ans,now);
            return;
        }
        if(depth == n) return;
        dfs(dfs,used,depth+1,now);
        dfs(dfs,used+1,depth+1,now^a[depth]);
    };
    dfs(dfs);
    cout << ans << endl;
    return 0;
}