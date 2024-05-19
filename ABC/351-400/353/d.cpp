#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint = modint998244353;
using ll = long long;

ll pow(int a,int b){
    ll res = 1;
    rep(i,b) res *= (ll)a;
    return res;
}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    mint ans = 0;
    rep(i,n) ans += (mint)a[i]*i;
    auto f = [&](int v)->int{
        int res = 0;
        while(v > 9){
            v /= 10;
            res++;
        }
        return res+1;
    };
    vector<ll> edigits(n);
    rep(i,n) edigits[i] = f(a[i]);
    vector<ll> digits(11);
    rep(i,n) digits[edigits[i]]++;
    rep(i,n-1){
        digits[edigits[i]]--;
        rep(j,11){
            //cout << a[i]*edigits[j]*pow(10,j) << endl;
            ans += (mint)a[i]*digits[j]*pow(10,j);
        }
    }
    cout << ans.val() << endl;
    return 0;
}