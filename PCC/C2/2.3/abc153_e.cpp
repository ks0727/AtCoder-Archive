#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;

void chmin(int &a, int b){
    a = min(a,b);
}

int main(){
    int h,n;
    cin >> h>> n;
    const int INF = 1e9;
    vector dp(n+1,vector<int>(h+1,INF));
    dp[0][0] = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        dp[i+1] = dp[i];
        rep(j,h+1){
            int nj = min(j+a,h);
            chmin(dp[i+1][nj],dp[i][nj]);
            chmin(dp[i+1][nj],dp[i+1][j]+b);
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}