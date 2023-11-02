#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a[i+1];
    int m;
    cin >> m;
    set<int> b;
    rep(i,m){
        int mochi;
        cin >> mochi;
        b.insert(mochi);
    }
    int x;
    cin >> x;
    vector<vector<bool> > dp(n+1,vector<bool>(x+1));
    dp[0][0] = true;
    const int MX = 1e9;
    bool ok = true;
    for(int i=1;i<=MX;i++){
        bool done = true;
        if(!ok) break;
        for(int j=0;j<=(x);j++){
            if(!ok) break;
            for(int k=1;k<=n;k++){
                if(dp[i-1][j]) dp[i][j] = true;
                if(dp[i][j]) continue;
                if(dp[i-1][j-a[k]] && !b.count(j-a[k])){
                    done = false;
                    dp[i][j] = true;
                }
            }
        }
        if(done){
                ok = false;
                break;
            }
    }
    rep(i,n+1){
        rep(j,x+1){
            cout << dp[i][j];
        }
        cout << endl;
    }
    cout << endl;
    if(dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}