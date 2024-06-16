#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;

// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv {
    int n; vector<mint> d;
    modinv(): n(2), d({0,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
    int n; vector<mint> d;
    modfact(): n(2), d({1,1}) {}
    mint operator()(int i) {
    while (n <= i) d.push_back(d.back()*n), ++n;
    return d[i];
    }
    mint operator[](int i) const { return d[i];}
}facts;
struct modfactinv {
    int n; vector<mint> d;
    modfactinv(): n(2), d({1,1}) {}
    mint operator()(int i) {
        while (n <= i) d.push_back(d.back()*invs(n)), ++n;
        return d[i];
    }
    mint operator[](int i) const { return d[i];}
} ifacts;

mint comb(int n, int k) {
    if (n < k || k < 0) return 0;
    return facts(n)*ifacts(k)*ifacts(n-k);
}

int main(){
    int n = 26;
    int k;cin >> k;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<mint> dp(k+1);
    dp[0] = 1;

    rep(i,n){
        vector<mint> old(k+1);
        swap(old,dp);
        rep(j,k+1){
            rep(a,c[i]+1){
                int nj = j+a;
                if(nj > k) break;
                dp[nj] += old[j]*comb(nj,a);
            }
        }
    }
    mint ans = 0;
    rep(i,k) ans += dp[i+1];
    cout << ans.val() << endl;
    return 0;
}