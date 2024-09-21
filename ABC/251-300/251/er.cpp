#include <iostream>
using namespace std;
using ll = long long;
ll a[3<<17];
ll dp1[3<<17][2],dp2[3<<17][2];
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  //dp1: 1回目に使うものとする(N回目はどちらでもok)
  dp1[0][0] = 0;
  dp1[0][1] = 3e18;
  for(int i=0;i<n;i++){
    dp1[i+1][0] = dp1[i][1];
    dp1[i+1][1] = min(dp1[i][0],dp1[i][1]) +  a[i];
  }
  //dp2 : 1回目に使わない(N回目に必ず使う必要あり)
  dp2[0][0] = 3e18;
  dp2[0][1] = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
      dp2[i+1][0] = dp2[i][1];
      dp2[i+1][1] = min(dp2[i][0],dp2[i][1])+a[i];
    }
  }
  ll ans = min(dp1[n][0],dp1[n][1]);
  ans = min(ans,dp2[n][1]);
  cout << ans << endl; 
  return 0;
}

