#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

mint dp[1005][1005];

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    rep(i,K+1)rep(j,N+1) dp[i][j] = 0;
    dp[0][0] = 1;
    mint p = mint(1)/M;
    mint ans = 0;
    for(int i=1;i<(K+1);i++){
        rep(j,N+1){
            for(int l=1;l<=M;l++){
                mint add = 0;
                if(j-l >= 0) add = p*dp[i-1][j-l];
                dp[i][j] += add;
            }
            if(j >= N-M+1 && j <= N-1){
                for(int l=1;l<=j-N+M;l++) dp[i][j] += p*dp[i-1][N-l];
            }
        }
    }
    rep(i,K+1){
        ans += dp[i][N];
    }
    cout << ans.val() << endl;
    return 0;
}
