#include <iostream>
#include <atcoder/modint>
#include <vector>
using namespace atcoder;
using namespace std;
using mint = modint1000000007;
using ll = long long;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> f(n);
  for(int i=0;i<n;++i) cin >> f[i],f[i]--;
  vector<mint> dp(n+1);
  vector<mint> sum(n+1);
  vector<bool> took(m+1);
  dp[0] = 1;
  sum[0] = 0;
  int r = 0;
  for(int l=0;l<n;++l){
    while(r<n && !took[f[r]]){
      took[f[r]] = true;
      sum[r+1] = sum[r] + dp[r];
      dp[r+1] += sum[r+1] - sum[l]; // 今[l,r)の範囲でサプリを摂取可能
      r++;
    }
    if(r == l) r++;
    else took[f[l]] = false;
  }
  cout << dp[n].val() << endl;
  return 0;
}

