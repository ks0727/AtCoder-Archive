#include <iostream>
#include<vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<mint> dp(10);
  dp[a[0]] = 1;
  for(int i=1;i<n;i++){
    vector<mint> old(10);
    swap(old,dp);
    for(int j=0;j<10;j++){
      int add = (j + a[i])%10;
      int multi = (j*a[i])%10;
      dp[add] += old[j];
      dp[multi] += old[j];
    }
  }
  for(int i=0;i<10;i++){
    cout << dp[i].val() << endl;
  }
  return 0;
}

