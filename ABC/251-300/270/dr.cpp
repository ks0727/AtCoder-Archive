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
        {
            int cur = 0;
            for(int x : a){
                if(j >= x) cur = max(dp[1][j-x]+x,cur);
            }
            dp[0][j] = cur;
        }
        {
            int cur = 1001001001;
            for(int x : a){
                if(j >= x) cur = min(dp[0][j-x],cur);
            }
            dp[1][j] = cur;
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}