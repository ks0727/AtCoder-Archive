#include <iostream>
#include <vector>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  vector<mint> dp(3001,1);
  for(int i=0;i<n;i++){
    vector<mint> old(3001);
    swap(dp,old);
    for(int j=a[i];j<=b[i];j++){
      dp[j] = old[j];
    }
    for(int j=0;j<3000;j++) dp[j+1] = dp[j]+dp[j+1];
  } 
  cout << dp[b[n-1]].val() << endl;
  return 0;
}
