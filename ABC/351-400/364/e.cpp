#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(x+1,vector<int>(y+1)));

    rep(i,n){
        rep(j,x+1){
            rep(k,y+1){
                if(j - a[i] < 0 || k - b[i] < 0) continue;
                dp[i+1][j][k] = max(dp[i][j-a[i]][k-b[i]]+1,dp[i][j][k]);
            }
        }
    }
    cout << dp[n][x][y] << endl;
    return 0; 
}