#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n,x;
    cin >> n >> x;
    vector<double> p(n);
    rep(i,n) cin >> p[i],p[i] /= 100;
    const long long INF = 1e18;
    vector<vector<double>  > dp(x+1,vector<double>(n+1,INF));
    dp[0][0] = 0.0;
    return 0;
}