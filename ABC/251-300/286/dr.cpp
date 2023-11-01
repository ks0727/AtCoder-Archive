#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n+1),b(n+1);
    rep(i,n) cin >> a[i+1] >> b[i+1];
    vector<vector<bool> > dp(n+1,vector<bool>(10001));
    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=(x);j++){
            if(dp[i-1][j]) dp[i][j] = true;
            for(int k=1;k<=b[i];k++){
                if(dp[i-1][j] && j+a[i]*k <= x) dp[i][j+a[i]*k] = true;
            }
        }
    }
    if(dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}