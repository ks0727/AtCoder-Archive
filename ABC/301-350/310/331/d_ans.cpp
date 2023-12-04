#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
    int n,q;
    cin >> n >> q;
    vector<string> p(n);
    rep(i,n) cin >> p[i];
    vector s(n+1,vector<int>(n+1));
    //二次元累積和
    rep(i,n)rep(j,n) s[i+1][j+1] = (p[i][j] == 'B');
    rep(i,n)rep(j,n) s[i+1][j+1] += s[i+1][j];
    rep(i,n)rep(j,n) s[i+1][j+1] += s[i][j+1];

    auto f = [&](int c, int d){
        ll res = s[c%n][d%n];
        res += s[n][n]*ll(c/n)*(d/n);
        res += s[n][d%n]*ll(c/n);
        res += s[c%n][n]*ll(d/n);
        return res;
    };

    rep(qi,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        c++; d++;
        ll ans = f(c,d) - f(c,b) - f(a,b) + f(a,b);
        cout << ans << '\n';
    }
    return 0;
}