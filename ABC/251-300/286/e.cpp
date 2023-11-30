#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<string> s(n);
    const int INF = 1e9;
    vector<vector<int> > dp(n,vector<int>(n,INF));
    vector<vector<ll> > souv(n,vector<ll>(n,-1));
    rep(i,n) cin >> s[i];
    int q;
    cin >> q;
    rep(i,n){
        rep(j,n){
            if(i == j){
                dp[i][j] = 0;
            }
            if(s[i][j] == 'Y'){
                dp[i][j] = 1;
                souv[i][j] = a[i] + a[j];
            }
        }
    }
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] < dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][j];
                    souv[i][j] = souv[i][j];
                }
                else if(dp[i][j] >  dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                    souv[i][j] = souv[i][k] + souv[k][j] - a[k];
                }
                else if(dp[i][j] == dp[i][k] + dp[k][j]){
                    if(souv[i][j] <= souv[i][k]+souv[k][j]){
                        souv[i][j] = souv[i][k] + souv[k][j] - a[k];
                    }else{
                        souv[i][j] = souv[i][j];
                    }
                }
            }
        }
    }
    rep(qi,q){
        int u,v;
        cin >> u >> v;
        u--; v--;
        if(dp[u][v] == INF){
            cout << "Impossible" << '\n';
        }else{
            cout << dp[u][v] << ' ' << souv[u][v] << '\n';
        }
    }
    return 0;
}