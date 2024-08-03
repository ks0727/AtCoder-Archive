#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int dp[81][81][10001];

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    const int INF = 1e9;
    rep(i,n+1)rep(j,n+1)rep(k,x+1) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,n){
        for(int j=0;j<=i;j++){
            rep(k,x+1){
                //選ぶ時
                if(k-a[i] >= 0) dp[i+1][j+1][k] = min(dp[i][j][k-a[i]]+b[i],dp[i+1][j+1][k]);
                //選ばない時
                dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
            }   
        }
    }
    int ans = 0;
    rep(j,n+1){
        rep(k,x+1){
            if(dp[n][j][k] <= y) ans = max(ans,min(j+1,n));
        }
    }
    cout << ans << endl;
    return 0;
}