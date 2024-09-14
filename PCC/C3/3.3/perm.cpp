#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;++i)
using ll = long long;
using mint = modint1000000007;
mt19937_64 rng(58);
const ll mod = 1e16+61;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> p(n);
    rep(i,n) cin >> p[i],p[i]--;
    vector xs(41,vector<ll>(n));
    vector ss(41,vector<ll>(n+1));
    vector hs(41,vector<ll>(n+1));
    vector<int> hash(n);
    rep(i,n) hash[i] = rng()%mod;
    rep(i,n) xs[0][i] = i;
    ll rn = rng();
    rep(i,n){
      ss[0][i+1] += ss[0][i]+xs[0][i];
      hs[0][i+1] = hs[0][i]*rn%mod + xs[0][i]%mod;
    }

    rep(k,40){
      rep(i,n){
        xs[k+1][i]  = p[xs[k][i]];
        ss[k+1][i+1] = ss[k+1][i] + xs[k+1][i];
        hs[k+1][i+1] = hs[k+1][i]*rn%mod + xs[k+1][i]%mod;
      }
    }

    while(q--){
      int l,r;
      cin >> l >> r;
      l--;
      mint res = 0;
      bool done = false;
      rep(k,40){
        if(done) break;
        res += ss[k+1][r]-ss[k+1][l]+r-l;
        if(hs[k+1][r]-hs[k+1][l] == hs[0][r] - hs[0][l]){
          cout << res.val() << endl;
          done = true;
          break;
        }
      }
    }
    return 0;
}