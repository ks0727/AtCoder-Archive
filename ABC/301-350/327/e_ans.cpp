#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    const double INF = 1e18;
    vector<double> dp(n+1,-INF);
    dp[0] = 0;
    rep(i,n){
        vector<double> pre(n+1,-INF);
        swap(dp,pre);
        rep(j,n+1){
            if(pre[j] == -INF) continue;
            dp[j] = max(dp[j],pre[j]);
            if(j+1 <= n){
                dp[j+1] = max(dp[j+1],pre[j]*0.9+p[i]);
            }
        }
    }

    double ans = -INF, x = 1;
    for(int i =1;i<=n;i++){
        double now = dp[i];
        now /= x;
        now -= 1200/sqrt(i);
        ans = max(ans,now);
        x = x * 0.9 + 1;
    }
    printf("%.10f\n",ans);
    return 0;
}