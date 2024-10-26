#include <iostream>
using namespace std;
using ll = long long;

ll modpow(ll x, ll t, ll mod){
  if(t == 0) return 1;
  x %= mod;
  ll res = (modpow(x,t/2,mod)%mod)*(modpow(x,t/2,mod)%mod)%mod;
  if (t%2 ==1){
    res *= x;
    res %= mod;
  }
  return res;
}

int main(){
  const int mod = 998244353;
  ll n,k,m;
  cin >> n >> k >> m;
  ll x = modpow(k,n,mod-1);
  ll ans = modpow(m,x,mod);
  if(m%mod==0) ans = 0;
  cout << ans << endl;
  return 0;
}

