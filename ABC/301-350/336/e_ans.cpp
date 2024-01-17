#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll dp[16][2][130][130];

int main(){
    ll n;
    cin >> n;
    n++;
    vector<int> digit(n);
    while(n){
        digit.push_back(n%10);
        n /= 10;
    }
    reverse(digit.begin(),digit.end());
    int m = digit.size();

    ll ans = 0;
    for(int k = 1;k<=126;k++){
        rep(i,m+1)rep(j,2)rep(s,k+1)rep(r,k) dp[i][j][s][r] = 0;
        dp[0][0][0][0] = 1;
        rep(i,m)rep(j,2)rep(s,k+1)rep(r,k){
            rep(d,10){
                int ni = i + 1;
                int nj = j;
                int ns = s+d;
                int nr = (r*10+d)%k;
                if(ns > k) continue;
                if(nj == 0){
                    if(digit[i] < d) continue;
                    if(digit[i] > d) nj = 1;
                }

                dp[ni][nj][ns][nr] += dp[i][j][s][r];
            }
        }
        ans += dp[m][1][k][0];
    }
    cout << ans << endl;
    return 0;
}