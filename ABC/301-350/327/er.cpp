#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    const double INF = 1e18;
    vector<vector<double> > dp(n+1,vector<double>(n+1,-INF));
    rep(i,n+1) dp[i][0] = 0;
    for(int i=1;i<=(n);i++){
        for(int j=1;j<=(n);j++){
            if(dp[i-1][j-1] == -INF) continue;
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i-1][j-1]*0.9+p[i-1],dp[i][j]);
        }
    }
    double ans = -INF , x = 1;
    for(int i=1;i<=(n);i++){
        double now = dp[n][i];
        now /= x;
        now -= 1200/sqrt(i);
        ans = max(ans,now);
        x = x * 0.9 + 1;
    }
    printf("%.10lf\n",ans);
    return 0;
}