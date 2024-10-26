#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main(){
  int h,w,k;
  cin >> h >> w >> k;
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector dp(k+1,vector<mint>(3));
  // 0 : (x2,y2)
  // 1 : (x2,y)
  // 2 : (x,y2)
  // 3 : (x,y)
  dp[0][0] = x1==x2&&y1==y2;
  dp[0][1] = x1==x2&&y1!=y2;
  dp[0][2] = x1!=x2&&y1==y2;
  dp[0][3] = x1!=x2&&y1!=y2;

  for(int i=0;i<k;i++){
    dp[i+1][0] = dp[i][1]+dp[i][2];
    dp[i+1][1] = dp[i][3]+dp[i][0]*(w-1);
    if(w>=2) dp[i+1][1] += dp[i][1]*(w-2);
    dp[i+1][2] = dp[i][3]+dp[i][0]*(h-1);
    if(h>=2) dp[i+1][2] += dp[i][2]*(h-2);
    if(h>=2) dp[i+1][3] += (h-2)*dp[i][3];
    if(w>=2) dp[i+1][3] += (w-2)*dp[i][3];
    dp[i+1][3] += dp[i][1]*(h-1);
    dp[i+1][3] += dp[i][2]*(w-1);
  }
  cout << dp[k][0].val() << endl;
  return 0;
}

