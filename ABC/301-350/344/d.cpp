#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string> > ss(n);
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            string ns;
            cin >> ns;
            ss[i].push_back(ns);
        }
    }
    const int INF = 1001001001;
    vector<vector<int> > dp(n+5,vector<int>(t.size()+3,INF));
    dp[0][0] = 0;
    rep(i,n){
        dp[i+1] = dp[i];
        for(string ns : ss[i]){
            rep(j,t.size()+1){
                if(j + ns.size() > t.size()) continue;
                if(ns != t.substr(j,ns.size())) continue;
                dp[i+1][j+ns.size()] = min(dp[i][j]+1,dp[i+1][j+ns.size()]);
            }
        }
    }
    if(dp[n][t.size()] != INF) cout << dp[n][t.size()] << endl;
    else cout << -1 << endl;
    return 0;
}