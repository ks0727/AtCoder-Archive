#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;

ll pow(int a,int b){
    ll res = 1;
    rep(i,b) res *= a;
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll x = n;
    int digit = 1;
    while(x > 9){
        digit++;
        x/=10;
    }
    ll r = pow(10,digit);
    mint ans = n*(mint(r).pow(n)-1)/(r-1);
    cout << ans.val() << endl;
    return 0; 
}