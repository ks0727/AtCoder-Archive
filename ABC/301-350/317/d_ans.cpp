#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;

void chmin(ll &x,ll y){
    x = min(x,y);
}

int main(){
    int n;
    cin >> n;
    int w = 0;

    vector<P> data;
    rep(i,n){
        int x,y,z;
        cin >> x >> y >> z;
        int a = max(0,(y-x+1)/2);
        w +=z;
        data.emplace_back(a,z*2);
    }
    const ll INF = 1e18; 
    vector<vector<ll>> dp(n+1, vector<ll>(w+1,INF));
    dp[0][0] = 0;
    rep(i,n){
        auto [a,z] = data[i];
        rep(j,w+1){
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][min(w,j+z)],dp[i][j]+a);
        }
    }

    ll ans  = dp[n][w];
    cout << ans << endl;
}