#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    vector<vector<P> > dp(n+1,vector<P>(2));
    rep(i,2) dp[0][i] = P(0,0);
    for(int i=1;i<(n+1);i++){
        rep(j,k){
            {
                if(i-a[j]>=0){
                    dp[i][0].first = max(dp[i][0].first,dp[i-a[j]][1].first + a[j]);
                    dp[i][0].second = max(dp[i][0].second,dp[i-a[j]][1].second);
                }
            }
            {
                if(i-a[j]>=0){
                    dp[i][1].first = max(dp[i][1].first,dp[i-a[j]][0].first);
                    dp[i][1].second = max(dp[i][1].second,dp[i-a[j]][0].second + a[j]);
                }
            }
        }
    }
    rep(i,2){
        rep(j,n+1){
            cout << dp[j][i].first << ' ' << dp[j][i].second << ' ';
        }
        cout << endl;
    }
    cout << dp[n][0].first << endl;
    return 0;
}