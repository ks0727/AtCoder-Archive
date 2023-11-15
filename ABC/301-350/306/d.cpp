#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<ll> > dp(n+1,vector<ll>(2));
    vector<vector<bool> > poison(n+1,vector<bool>(2));
    dp[0][0] = dp[0][1] = 0;
    vector<ll> x(n+1),y(n+1);
    rep(i,n) cin >> x[i+1] >> y[i+1];
    for(int i=1;i<=(n);i++){
        if(poison[i-1][0] && poison[i-1][1]){
            if(x[i] == 0){
                dp[i][0] = max(dp[i-1][0]+y[i],dp[i-1][1] + y[i]);
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
                poison[i][0] = false;
                poison[i][1] = true;
            }else{
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
                poison[i][0] = true;
                poison[i][1] = true;
            }
        }
        if(!poison[i-1][0] && !poison[i-1][1]){
            if(x[i] == 0){
                dp[i][0] = max(dp[i-1][0]+y[i],dp[i-1][1] + y[i]);
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
                poison[i][0] = false;
                poison[i][1] = false;
            }else{
                dp[i][0] = max(dp[i-1][0]+y[i],dp[i-1][1] + y[i]);
                dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
                poison[i][0] = true;
                poison[i][1] = false;
            }
        }
        if(!poison[i-1][0] && poison[i-1][1]){
            if(x[i] == 0){
                dp[i][0] = max(dp[i-1][0]+y[i],dp[i-1][1] + y[i]);
                poison[i][0] = false;
                if(dp[i-1][0] > dp[i-1][1]){
                    dp[i][1] = dp[i-1][0];
                    poison[i][1] = false; 
                }else{
                    dp[i][1] = dp[i-1][1];
                    poison[i][1] = true;
                }
            }else{
                dp[i][0] = dp[i-1][0]+y[i];
                poison[i][0] = true;
                if(dp[i-1][0]>=dp[i-1][1]){
                    dp[i][1] = dp[i-1][0];
                    poison[i][0] = false;
                }else{
                    dp[i][1] = dp[i-1][1];
                    poison[i][0] = true;
                }
            }
        }
        if(poison[i-1][0] && !poison[i-1][1]){
            if(x[i] == 0){
                dp[i][0] = max(dp[i-1][0]+y[i],dp[i-1][1] + y[i]);
                poison[i][0] = false;
                if(dp[i-1][0] > dp[i-1][1]){
                    dp[i][1] = dp[i-1][0];
                    poison[i][1] = true;
                }else{
                    dp[i][1] = dp[i-1][1];
                    poison[i][1] = false;
                }
            }else{
                dp[i][0] = dp[i-1][1] + y[i];
                poison[i][0] = true;
                if(dp[i-1][0] > dp[i-1][1]){
                    dp[i][1] = dp[i-1][0];
                    poison[i][1] = true;
                }else{
                    dp[i][1] = dp[i-1][1];
                    poison[i][1] = false;
                }
            }
        }
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
    return 0;
}