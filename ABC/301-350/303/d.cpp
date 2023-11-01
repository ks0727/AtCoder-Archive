#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    ll x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int size = s.size();
    vector<vector<ll> > dp(2,vector<ll>(size));

    for(int i=0;i<size;i++){
        if(i == 0){
            if(s[0] == 'A'){
                dp[0][0] = z + x;
                dp[1][0] = y;
            }else{
                dp[0][0] = y + z;
                dp[1][0] = x;
            }
            continue;
        }
        if(s[i] == 'A' && s[i-1] == 'A'){
            dp[0][i] = min(dp[0][i-1]+x,dp[1][i-1]+z+x);
            dp[1][i] = min(dp[0][i-1]+z+y,dp[1][i-1]+y);
        }
        if(s[i] == 'a' && s[i-1] == 'A'){
            dp[0][i] = min(dp[0][i-1]+y,dp[1][i-1]+z+y);
            dp[1][i] = min(dp[0][i-1]+x+z,dp[1][i-1]+x);
        }
        if(s[i] == 'A' && s[i-1] == 'a'){
            dp[0][i] = min(dp[0][i-1]+x,dp[1][i-1]+z+x);
            dp[1][i] = min(dp[0][i-1]+y+z,dp[1][i-1]+y);
        }
        if(s[i] == 'a' && s[i-1] == 'a'){
            dp[0][i] = min(dp[0][i-1]+y,dp[1][i-1]+y+z);
            dp[1][i] = min(dp[0][i-1]+z+x,dp[1][i-1]+x);
        }
    }
    ll ans = min(dp[0][size-1],dp[1][size-1]);
    cout << ans << endl;
    return 0;
}