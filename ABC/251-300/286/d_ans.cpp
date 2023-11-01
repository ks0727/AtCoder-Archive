#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    int a[50];
    int b[50];
    bool dp[51][10001];
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n)rep(j,x) dp[i][j] = false;
    dp[0][0] = true;
    rep(i,n){
        for(int j=0;j<=x;j++){
            for(int k =0;k<=b[i];k++){
                if(j >= a[i]*k){
                    if(dp[i][j-k*a[i]]) dp[i+1][j] = true;
                }
            }
        }
    }
    if(dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}