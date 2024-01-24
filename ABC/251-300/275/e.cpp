#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

mint dp[1002][1002];

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    rep(i,K+1)rep(j,N+1) dp[i][j] = 0;
    dp[0][0] = 1;
    mint p = 1/mint(M);
    for(int i=1;i<(K+1);i++){
        rep(j,N+1){
            if(j >= N-M+1 && j <= N-1){
                for(int l=1;l<=M;l++) if(j-l >= 0) dp[i][j] += p*dp[i-1][j-l];
                for(int l=1;l<=M-N+j;l++) dp[i][j] += p*dp[i-1][N-l];
            }else{
                for(int l=1;l<=(M);l++) if(j-l >= 0) dp[i][j] += p*dp[i-1][j-l];
            }
        }
    }
    cout << dp[K][N].val() << endl;
    return 0;
}
