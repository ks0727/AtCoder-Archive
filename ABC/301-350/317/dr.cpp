#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,int>;

int main(){
    int n;
    cin >> n;
    vector<P> data;
    int aoki = 0, takahashi = 0;
    rep(i,n){
        int x,y,z;
        cin >> x >> y >> z;
        if(x > y) takahashi += z;
        else{
            aoki+= z;
            ll sum = x + y;
            sum /= 2;
            ll need = sum + 1 - (ll)x;
            data.push_back(P(need,z));
        }
    }
    if(takahashi > aoki){
        cout << 0 << endl;
        return 0;
    }
    int mean = (takahashi+aoki)/2 + 1;
    int over = mean - takahashi;
    int size = data.size();
    const int MX = 1e5;
    const ll INF = 1e18;
    vector<vector<ll> > dp(size+1,vector<ll>(MX+1,INF));
    dp[0][0] = 0;
    ll ans = INF;
    for(int i=1;i<=(size);i++){
        ll need = data[i-1].first;
        int seats = data[i-1].second;
        dp[i] = dp[i-1];
        for(int j = seats; j < MX+1;j++){
            if(j == seats || dp[i-1][j-seats] != INF){
                dp[i][j] = min(dp[i][j],dp[i-1][j-seats]+need);
                if(j >= over) ans = min(ans,dp[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}