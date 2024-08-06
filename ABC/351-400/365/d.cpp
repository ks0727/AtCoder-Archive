#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    const int INF = 1e9;
    // 0 : グー
    // 1 : チョキ
    // 2 : パー
    vector dp(n+1,vector<int>(3,-INF));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    rep(i,n){
        if(s[i] == 'R'){
            dp[i+1][0] = max(dp[i][1],dp[i][2]);
            dp[i+1][2] = max(dp[i][0]+1,dp[i][1]+1);
        }else if(s[i] == 'P'){
            dp[i+1][1] = max(dp[i][0]+1,dp[i][2]+1);
            dp[i+1][2] = max(dp[i][0],dp[i][1]);
        }else if(s[i] == 'S'){
            dp[i+1][0] = max(dp[i][1]+1,dp[i][2]+1);
            dp[i+1][1] = max(dp[i][0],dp[i][2]);
        }
    }
    int ans = 0;
    ans = max({dp[n][0],dp[n][1],dp[n][2]});
    cout << ans << endl;
    return 0;
}