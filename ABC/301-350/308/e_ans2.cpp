#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    ll ans = 0;
    string T= "MEX";
    auto mex = [&](int k){
        int res = 0;
        while((k>>res)&1) res++;
        return res;
    };
    vector dp(4,vector<ll>(8));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,3)if(s[i] == T[j]){
            rep(k,8){
                dp[j+1][k|1<<a[i]] += dp[j][k];
            }
        }
    }
    ll ans = 0;
    rep(k,8) ans += dp[3][k]*mex(k);
    cout << ans << endl;
    return 0;
}