#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

mint dp[81][81][81];

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n){
        rep(j,i) dp[i][j][2] += 1;
        rep(j,i){
            rep(k,n){
                mint now = dp[i][j][k];
                if(now == 0) continue;
                for(int x=i+1;x<n;++x){
                    if(a[x]-a[i] == a[i]-a[j]){
                        dp[x][i][k+1] += now;
                    }
                }
            }
        }
    } 
    vector<mint> ans(n+1);
    ans[1] = n;
    for(int k=2;k<=n;k++){
        rep(i,n)rep(j,i) ans[k] += dp[i][j][k];
    }
    for(int i=1;i<=n;i++) cout << ans[i].val() <<' ';
    cout << endl;
    return 0;
}