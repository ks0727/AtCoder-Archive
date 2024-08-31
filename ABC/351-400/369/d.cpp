#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector dp(n+1,vector<ll>(2));
    dp[0][1] = -1001001001;
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(i == 0){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][0]+a[i];
        }else{
            dp[i+1][0] = max(dp[i][0],dp[i][1]+a[i]*2);
            dp[i+1][1] = max(dp[i][0]+a[i],dp[i][1]);
        }
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
    return 0;
}