#include <iostream>
#include<atcoder/modint>
#include<vector>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  mint ans = 0;
  vector<mint> dp(k+1);
  for(int i=0;i<n;i++){
    dp[0] += 1;
    vector<mint> old(k+1);
    swap(dp,old);
    for(int j=0;j<k+1;j++){
      for(int c=0;c<k-j+1){
        dp[j+c] = old[j] * mint(a[i]).pow(c)*comb(k-j,c);
      }
    }
    ans += dp[k];
  }
  cout << ans.val() << endl;
  return 0;
}

