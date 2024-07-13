#include <iostream>
#include <vector>
using namespace std;

int dp[51][51][10001];

int main(){
  int w;
  cin >> w;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n+1;++i){
    for(int j=0;j<=k;++j){
      for(int l=0;l<=w;++l){
        dp[i][j][l] = 0;
      }
    }
  }
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    for(int j=0;j<=k;j++){
      for(int l=0;l<=w;++l){
        if(j >= 1 && l-a >= 0){
          dp[i+1][j][l] = max(dp[i][j-1][l-a]+b,dp[i][j][l]);
        }else{
          dp[i+1][j][l] = dp[i][j][l];
        }
      }
    }
  }
  cout << dp[n][k][w] << endl;
  return 0;
}

