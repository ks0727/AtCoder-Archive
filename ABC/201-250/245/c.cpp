#include <iostream>
using namespace std;
using ll = long long;
ll a[2<<17],b[2<<17];
bool dp[2<<17][2];
int main(){
  int n; ll k;
  cin >> n >> k;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  for(int i=0;i<n-1;i++){
    if((dp[i][0]&&abs(a[i+1]-a[i]) <= k) || (dp[i][1]&&abs(a[i+1]-b[i])<=k)) dp[i+1][0] = true;
    if((dp[i][0]&&abs(b[i+1]-a[i]) <= k) || (dp[i][1]&&abs(b[i+1]-b[i])<=k)) dp[i+1][1] = true;
  }
  if(dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

