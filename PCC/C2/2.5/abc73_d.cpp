#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<int> R(r);
    rep(ri,r) cin >> R[ri],R[ri]--;
    const ll INF = 1e18;
    vector dist(n,vector<ll>(n,INF));
    rep(mi,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(k,n)rep(i,n)rep(j,n) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    vector<int> is;
    rep(i,r) is.push_back(i);
    ll ans = INF;
    do{
        ll now = 0;
        rep(i,r-1) now += dist[R[is[i]]][R[is[i+1]]];
        ans = min(now,ans);
    }while(next_permutation(is.begin(),is.end()));
    cout << ans << endl;
    return 0;
}