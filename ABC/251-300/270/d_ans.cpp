#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    vector dp(2,vector<int>(n+1));
    for(int j=1;j<=n;j++){
        { // i = 0
            int now = 0;
            for(int x : a){
                if(x <= j) now = max(now,dp[1][j-x]+x);
            }
            dp[0][j] = now;
        }
        { // i = 1
            int now = 1001001001;
            for(int x : a){
                if(x <= j) now = min(now,dp[0][j-x]);
            }
            dp[1][j] = now;
        }  
    }
    cout << dp[0][n] << endl;
    return 0;
}