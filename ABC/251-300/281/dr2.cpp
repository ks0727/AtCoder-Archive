#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll dp[105][105][100];

int main(){
    int n,k,d;
    cin >> n >> k >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n+1)rep(j,k+1)rep(l,d) dp[i][j][l] = -1;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,k+1){
            rep(l,d){
                ll now = dp[i][j][l];
                if(now == -1) continue;
                {// use
                    int ni = i+1;
                    int nj = j+1;
                    int nl = (l+a[i])%d;
                    dp[ni][nj][nl] = max(now+(ll)a[i],dp[ni][nj][nl]);
                }
                {//not use
                    int ni = i+1;
                    int nj = j;
                    int nl = l;
                    dp[ni][nj][nl] = max(now,dp[ni][nj][nl]);
                }
            }
        }
    }
    cout << dp[n][k][0] << endl;
    return 0;
}