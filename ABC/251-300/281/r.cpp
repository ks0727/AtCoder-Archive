#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long dp[105][105][105];
int main(){
  long long n,k,d;
  cin >> n >> k >> d;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  for(int i=0;i<n+1;i++)for(int j=0;j<k+1;j++)for(int l=0;l<d+1;l++) dp[i][j][l] = -1;
  dp[0][0][0] = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<k+1;j++){
      for(long long l=0;l<d;l++){
        if(dp[i][j][l] == -1) continue;
          dp[i+1][j+1][(l+a[i])%d] = max(dp[i+1][j+1][(l+a[i])%d],dp[i][j][l]+a[i]);
          dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
      }
    }
  }
  cout << dp[n][k][0] << endl;
} 


