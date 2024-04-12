#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(0);i++)
using ll = long long;
using mint = modint;

int main(){
    int a,m; ll x;
    cin >> a >> m >> x;
    mint::set_mod(m);
    auto f = [&](auto f,ll x)->pair<mint,mint>{
        if(x == 0) return{0,1};
        auto [s,p] = f(f,x/2);
        s = s+s*p;
        p *= p;
        if(x%2 == 1){
            s = s*a+1;
            p *= a;
            return {s,p};
        }else return {s,p};
    };
    mint ans = f(f,x).first;
    cout << ans.val() << endl;
    return 0;
}