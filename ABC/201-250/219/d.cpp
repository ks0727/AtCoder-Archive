#include <iostream>
#include<algorithm>
using namespace std;
int a[300],b[300];
int dp[301][301][301];
int main(){
  int n;
  cin >> n;
  int x,y;
  cin >> x >> y;
  const int INF = 1001001001;
  for(int i=0;i<=n;i++)for(int j=0;j<=x;j++)for(int k=0;k<=y;k++) dp[i][j][k] = INF;
  for(int i=0;i<n;i++)cin >> a[i] >> b[i];
  dp[0][0][0] = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=x;j++){
      for(int k=0;k<=y;k++){
        if(dp[i][j][k] == INF) continue;
        dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
        int nj = min(j+a[i],x);
        int nk = min(k+b[i],y);
        dp[i+1][nj][nk] = min(dp[i][j][k]+1,dp[i+1][nj][nk]);
      }
    }
  }
  int ans = dp[n][x][y];
  if(ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}

