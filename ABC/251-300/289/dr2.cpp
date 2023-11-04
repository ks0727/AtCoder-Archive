#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int x;
    cin >> x;
    vector<bool> mochi(x+1);
    rep(i,m){
        mochi[b[i]] = true;
    }
    vector<bool> dp(x+1);
    dp[0] = true;
    rep(i,x+1){
        if(mochi[i]) continue;
        rep(j,n){
            if(i-a[j] < 0) continue;
            if(dp[i-a[j]]) dp[i] = true;
        }
    }
    if(dp[x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}