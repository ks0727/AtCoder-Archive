#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int n; cin >> n;
    vector<int> p(n),a(n),b(n);
    for(int i=0;i<n;i++) cin >> p[i] >> a[i] >> b[i];
    const int m = 1001;
    vector dp(n,vector<int>(m));
    for(int i=0;i<m;i++) dp[n][i] = i;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            int nj = j;
            if(j <= p[i]){
                nj += a[i];
            }else{
                nj = max(0,nj-b[i]);
            }
            dp[i][j] = dp[i+1][nj]; 
        }
    }
    vector<long long> bs(n+1);
    for(int i=0;i<n;i++) bs[i+1] = bs[i] + b[i];

    int q;
    cin >> q;
    for(int qi=0;qi<q;qi++){
        int x; cin >> x;
        int ans;
        if(x >= m){
            int i = upper_bound(bs.begin(),bs.begin()+n,x-m) - bs.begin();
            x -= bs[i];
            if(i < n) ans = dp[i][x];
            else ans = x;
        }else{
            ans = dp[0][x];
        }
        cout << ans << '\n';
    }
    return 0;
}