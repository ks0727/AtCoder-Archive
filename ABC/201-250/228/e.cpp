#include <iostream>
using namespace std;
const int MOD = 998244353;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  long long n,k,m;
  cin >> n >> k >> m;
  long long p = k%MOD;
  p = modpow(p,n,MOD);
  long long ans = m;
  ans = modpow(ans,p,MOD);
  cout << ans%MOD << endl;
  return 0;
}

