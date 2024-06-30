#include <iostream>
#include <vector>
using namespace std;

int main(){
  int d,g;
  cin >> d >> g;
  int p[d],c[d];
  for(int di=0;di<(d);di++) cin >> p[di] >> c[di];
  const long long INF = 1e18;
  vector<vector<long long> > dp(d+1,vector<long long>(1001,-INF));
  dp[0][0] = 0;
  for(int i=0;i<(d);i++){
      for(int j=0;j<=1000;j++){
          for(int k=0;k<=p[i];k++){
               if(j-k< 0) continue;
               if(dp[i][j-k] == -INF) continue;
               if(k != p[i]){
                 dp[i+1][j] = max(dp[i][j],dp[i][j-k]+(long long)100*(i+1)*k);
               }
               else dp[i+1][j] = max(dp[i+1][j],dp[i][j-k]+(long long)100*(i+1)*k+c[i]);
             
            }
        }
    }
  int ans = 1e9;
  for(int i=0;i<=(d);i++){
    for(int j=0;j<=(1000);j++){
        if(dp[i][j] >= g) ans = min(j,ans);
      }  
  }
  cout << ans << endl;
  return 0;
}
