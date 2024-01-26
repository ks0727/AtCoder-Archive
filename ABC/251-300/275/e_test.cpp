#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int dp[1005][1005];

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    rep(i,K+1)rep(j,N+1) dp[i][j] = 0;
    dp[0][0] = 1;
    for(int i=1;i<(K+1);i++){
        rep(j,N+1){
            for(int l=1;l<=M;l++){
                int add = 0;
                if(j-l >= 0) add = dp[i-1][j-l];
                dp[i][j] += add;
            }
            if(j >= N-M+1 && j < N){
                for(int l=1;l<=j-N+M;l++){
                    dp[i][j] += dp[i-1][N-l];
                } 
            }
        }
    }
    rep(i,K+1){
        rep(j,N+1){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
