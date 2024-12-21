#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<double> p(n);
  for(int i=0;i<n;i++) cin >> p[i],p[i]/=100;
  vector<double> dp(n+1);
  dp[0] = 1.0;
  for(int i=0;i<n;i++){
    vector<double> old(n);
    swap(dp,old);
    for(int j=0;j<n;j++){
      if(j+1<=n) dp[j+1] += dp[i][j]*p[i];
      dp[j] += dp[i][j]*(1-p[i]);
    }
  }
  vector<double> ep(x+1);
  ep[0] = 
  return 0;
}

