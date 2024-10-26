#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 998244353;
long long modpow(int x,int k,int mod){
  if(k == 0) return 1;
  long long r =  modpow(x,k/2,mod)%mod;
  r *= r;
  r %= mod;
  if(k % 2 == 1){
    r *= x;
    r %= mod;
  }
  return r;
}

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = (n+1)/2;
  long long ans = 0;
  string ns = "";
  for(int i=0;i<m;i++){
    int now = s[i]-'A';
    ns += s[i];
    ans += now*modpow(26,m-i-1,mod)%mod;
  }
  string t = ns;
  if(n%2 == 1) t.pop_back();
  reverse(t.begin(),t.end());
  ns += t;
  if(ns <= s) ans++;
  ans %= mod;
  cout << ans << '\n';
}
int main(){
  int t;
  cin >> t;
  while(t--) solve();  
  return 0;
}

