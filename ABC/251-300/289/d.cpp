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
    vector<vector<bool> > dp(n,vector<bool>(x));
    rep(i,n){
        rep(j,x){
            if(i == 0){
                dp[i][a[i]] = true;
            }else{
                if(dp[i-1][j]) dp[i][j] = true;
                if(dp[i-1])
            }   
        }
    }
}