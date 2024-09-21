#include <iostream>
#include <map>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
ll a[2<<17],s[2<<17];
mint dp[2<<17];
int main(){
  int n; ll k;
  cin >> n>> k;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) s[i+1] = s[i] + a[i];
  dp[0] = 1;
  mint sum = 1;
  map<ll,mint> mp;
  mp[0] = 1;
  for(int i=0;i<n;i++){
    dp[i+1] += sum;
    dp[i+1] -= mp[s[i+1]-k];
    sum += dp[i+1];
    mp[s[i+1]] += dp[i+1];
  }
  cout << dp[n].val() << endl;
  return 0;
}

