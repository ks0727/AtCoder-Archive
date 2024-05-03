#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

mint dp[101][101][2];

int main(){
    int n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    rep(i,101)rep(j,n)rep(k,2) dp[i][j][k] = 0;
    
    return 0;
}