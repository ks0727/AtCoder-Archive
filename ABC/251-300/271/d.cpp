#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool dp[105][2][10101];

int main(){
    int n,s;
    cin >> n >> s;
    vector<vector<int> > coin(2,vector<int>(n));
    rep(i,n){
        int a,b;
        cin >> a >> b;
        coin[0][i] = a;
        coin[1][i] = b;
    }
    dp[0][0][0] = true;
    dp[0][1][0] = true;
    for(int i=1;i<=n;i++){
        rep(j,2){
            for(int k=0;k<=s;k++){
                if(k-coin[j][i-1] >= 0) if(dp[i-1][0][k-coin[j][i-1]] || dp[i-1][1][k-coin[j][i-1]]) dp[i][j][k] = true;
            }
        }
    }
    if(dp[n][0][s] || dp[n][1][s]){
        cout << "Yes" << endl;
        int now = s;
        string ans = "";
        for(int i=n;i>0;i--){
            if(now >= 0 && dp[i][0][now]){
                ans += 'H';
                now -= coin[0][i-1];
            }
            else if(now >=0 && dp[i][1][now]){
                ans += 'T';
                now -= coin[1][i-1];
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    else cout << "No" << endl;
    return 0;
}