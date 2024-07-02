#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;

int main(){
    int n,k;
    cin >> n >> k;
    mint p = mint(2)/n/n;
    mint x = 1;
    rep(ki,k){
        x = x*(1-p*(n-1)) + (mint(1)-x)*p;
    }
    mint ans = x + (mint(1)-x)/(n-1)*(mint)(n+2)/2;
    cout << ans.val() << endl;
    return 0;
}