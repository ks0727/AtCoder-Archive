#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n;
    cin >> n;
    vector dp(n+1,vector<int>(n+2));
    dp[0][1] = 1;
    rep(i,n){
        for(int j=1;j<=i+2;j++){
            dp[i+1][j] = dp[i][j] + dp[i][j-1];
        }
    }
    rep(i,n){
        for(auto x : dp[i])if(x != 0) cout << x << ' '; cout << endl;
    }
    return 0;
}