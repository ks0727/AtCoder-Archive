#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using mint = modint998244353;
const ll mod = 998244353;

int main(){
    ll n,m;
    cin >> n >> m;

    mint ans;
    rep(i,60){
        if(m&(1<<i)){ //mのibit目が1だったら
            ll p = 1LL<<(i+1);
            ll r = n%p;
            ans += (n-r)/2;
            if(r >= (1LL <<i)){ //周期のあまりが1のところまで届いていたら
                ans += r-(1LL<<i);
            }
        }
    }
    cout << ans.val() << endl;
    return 0;
}