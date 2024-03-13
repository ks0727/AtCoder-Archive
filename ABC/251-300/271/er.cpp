#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

const ll INF = 1e18;
struct Edge{
    int from,to; ll cost;
    Edge(int from=0,int to = 0,ll cost = 0):from(from),to(to),cost(cost){}
};

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<Edge> es(m);
    rep(i,m){
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        es[i] = Edge(a,b,c);
    }
    vector<int> e(k);
    rep(i,k){
        int x;
        cin >> x; x--;
        e[i] = x;
    }
    vector<ll> dp(n,INF);
    dp[0] = 0;
    rep(i,k){
        dp[es[e[i]].to] = min(dp[es[e[i]].to],dp[es[e[i]].from]+es[e[i]].cost);
    }
    if(dp[n-1] == INF) dp[n-1] = -1;
    cout << dp[n-1] << endl;
    return 0;
}