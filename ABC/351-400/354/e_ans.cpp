#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    int n2 = 1<<n;
    vector<bool> dp(n2);
    rep(s,n2){
        bool now = false;
        rep(i,n)rep(j,n){
            if(i == j) continue;
            if((s>>i)&1 && (s>>j)&1){
                if(a[i] != a[j] && b[i] != b[j]) continue;
                if(!dp[s^(1<<i)^(1<<j)]) now = true;
            }
        }
        dp[s] = now;
    }
    if(dp[n2-1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}