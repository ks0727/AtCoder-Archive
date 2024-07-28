#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

void chmin(int &a, int b){a = min(a,b);}

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    const int INF = 1001001001;
    vector dp(x+1,vector<int>(n+1,INF));
    dp[0][0] = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        vector old(x+1,vector<int>(n+1,INF));
        swap(dp,old);
        rep(j,x+1)rep(k,n+1){
            int now = old[j][k];
            if(now == INF) continue;
            chmin(dp[j][k],old[j][k]); //i番目の料理を食べない時
            if(j+a <= x) chmin(dp[j+a][k+1],now+b); //i番目の料理を食べる時
        }
    }
    int ans = 0;
    rep(j,x+1)rep(k,n+1){
        if(dp[j][k] <= y) ans = min(ans,k);
    }
    if(ans < n) ans++;
    cout << ans << endl;
    return 0;
}