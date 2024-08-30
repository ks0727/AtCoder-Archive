#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector dp(n+1,vector<ll>(2));
    // 0 : 使っていない
    // 1 : 使っている
    dp[0][0] = 0; dp[0][1] = 0;
    rep(i,n){
        dp[i+1][1] = min(dp[i][0]+a[i],dp[i][1]+a[i]);
        dp[i+1][0] = dp[i][1]; 
    }
    rep(i,n+1){
        rep(j,2){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << min(dp[n][0],dp[n][1]) << endl;
    return 0;
}