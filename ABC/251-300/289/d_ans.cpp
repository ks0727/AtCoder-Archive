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
    rep(i,m) mochi[b[i]] = true;
    vector<bool> dp(x+1);
    dp[0] = true;
    for(int i=1;i<=x;i++){
        if(mochi[i]) continue;
        for(int na : a){
            int pi = i - na;
            if(0 <= pi && dp[pi]) dp[i] = true;
        }
    }
    if(dp[x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}