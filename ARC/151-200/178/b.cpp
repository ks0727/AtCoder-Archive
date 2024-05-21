#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
using mint = modint998244353;

mint sum(mint x){
    return x*(x+1)/2;
};

void solve(){
    int a1,a2,a3; cin >> a1 >> a2 >> a3;
    if(a3 < max(a1,a2) || a3 > max(a1,a2)+1){
        cout << 0 << '\n';
        return;
    }
    if(a1 == a2 && a2 == a3){
        mint res = 1;
        res = 8*mint(10).pow(a1-1);
        res = sum(res);
        cout << res.val() << endl;
        return;
    }
    if(a1 > a2) swap(a1,a2);
    if(a2 == a3){
        mint mx = mint(10).pow(a3)-mint(10).pow(a1-1)-mint(10).pow(a2-1);
        mint mn = mint(10).pow(a3)-mint(10).pow(a1) - mint(10).pow(a2-1);
        mx = sum(mx); mn = sum(mn);
        mint res = mx - mn;
        cout << res.val() << endl;
        return;
    }else if(a3 == a2+1){
        mint mx = mint(10).pow(a1)-1;
        mint mn = mint(10).pow(a1-1)-1;
        mx = sum(mx); mn = sum(mn);
        mint res = mx - mn;
        cout << res.val() << endl;
        return;
    }else{
        cout << 0 << endl;
        return;
    }
}

int main(){
    int t;
    cin >> t;
    rep(ti,t) solve();
    return 0;
}