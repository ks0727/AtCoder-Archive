#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> c(9);
    rep(i,9) cin >> c[i];
    vector<vector<string> > dp(10,vector<string>(n+1,""));
    rep(i,9){
        char add = (i+1) + '0';
        for(int j=0;j<=n;j++){
            if(j-c[i] >= 0){
                int num = (n-j)/c[i];
                cout << num << endl;
                string t(num,add);
                dp[i+1][j] = t+ dp[i][j-c[i]];
            } 
        }
    }
    cout << dp[9][n] << endl;
    return 0;
}