#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    vector<ll> imos(n+1);
    rep(i,m-1){
        int now = x[i]; int next = x[i+1];
        if(now > next) swap(now,next);
        imos[0] += next - now;
        imos[now] -= next - now;
        imos[now] += n + now - next;
        imos[next] -= n + now - next;
        imos[next] += next - now;
        imos[n] -= next - now;
    }
    vector<ll> cost(n+2);
    rep(i,n+1){
        cost[i+1] = cost[i]+imos[i];
    }
    const ll INF = 1e18;
    ll ans = INF;
    for(int i=1;i<n+1;i++) ans = min(ans,cost[i]);
    cout << ans << endl;
    return 0;
}