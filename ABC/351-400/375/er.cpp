#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1501][1501];
int main(){
  int n;
  cin >> n;
  const int M = 1501;
  const int INF = 1001001001;
  for(int i=0;i<M;i++)for(int j=0;j<M;j++) dp[i][j] = INF;
  dp[0][0] = 0;
  int sum = 0;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    sum += b;
    for(int j=0;j<M;j++){
      for(int k=0;k<M;k++){
        int nj = j+b;
        if(a == 1 && nj < M) dp[nj][k] = dp[j][k];
        else if(nj < M)dp[nj][k] = min(dp[nj][k],dp[j][k]+1);
        int nk = k+b;
        if(a == 2 && nk < M) dp[j][nk] = dp[j][k];
        else if(nk < M) dp[j][nk] = min(dp[j][nk],dp[j][k]+1);
        if(a == 3){
          int c = 
      }
    }
  }
  if(sum %3 != 0){
    cout << -1 << endl;
    return 0;
  }else{
    int k = sum/3;
    cout << dp[k][k] << endl;
    return 0;
  }
  return 0;
}

