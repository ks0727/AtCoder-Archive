#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using mint=modint998244353;
using ll = long long;

int main(){
    ll n,m; cin >> n >> m;
    mint ans = 0;
    rep(i,60){
        if(m & (1LL<< i)){ //iビット目が立っていたら
            ll cycle = 1LL<<(i+1); //2^(i+1)
            ll r = n%cycle;
            ans += (n-r)/2;
            //assert(r >= 0 && r <= (1LL<<(i+1)));
            if(r >= 1LL<<i) ans += r-(1LL<<i) + 1; //もしrが2^i以上であれば, オーバーしている分だけたす
        }
    }
    cout << ans.val() << endl;
    return 0;
}