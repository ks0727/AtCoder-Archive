#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<ll,ll>;
using mint = modint998244353;

mint dp[305][305][305][305];

int main(){
    int n,m;
    cin >> n >> m;
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    set<P> st;
    rep(i,m){
        ll x,y;
        cin >> x >> y;
        st.emplace(x,y);
    }
    rep(i,305)rep(j,305)rep(k,305)rep(l,305) dp[i][j][k][l] = 0;
    dp[0][0][0][0] = 1;
    auto func = [&](int j, int k, int l)->bool{
        ll ci = a*j+c*k+e*l; ll cj = b*j+d*k+f*l;
        P pos = P(ci,cj);
        if(st.count(pos)) return false;
        else return true;
    };

    for(int i=1;i<=n;i++){
        rep(j,n+1){
            rep(k,n+1){
                rep(l,n+1){
                    {
                        int pi = i-1, pj = j-1,pk =k, pl =l;
                        if(func(pj,pk,pl) && pj >= 0) dp[i][j][k][l] += dp[pi][pj][pk][pl];
                    }
                    {
                        int pi = i-1, pj = j,pk =k-1, pl =l;
                        if(func(pj,pk,pl) && pk >= 0) dp[i][j][k][l] += dp[pi][pj][pk][pl];
                    }
                    {
                        int pi = i-1, pj = j,pk =k, pl =l-1;
                        if(func(pj,pk,pl) && pl >= 0) dp[i][j][k][l] += dp[pi][pj][pk][pl];
                    }
                }
            }
        }
    }
    mint ans = 0;
    rep(i,n+1){
        rep(j,n+1){
            rep(k,n+1){
                if(i+k+j == n) ans += dp[n][i][j][k];
            }
        }
    }
    cout << ans.val() << endl;
    return 0;
}