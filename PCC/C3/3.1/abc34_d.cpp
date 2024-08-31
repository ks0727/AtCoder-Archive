#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll w[1000],p[1000];
int main(){
  int n,k;
  cin >> n >> k;
  vector dp(n+1,vector<double>(k+1));
  dp[0][0] = 0;
  for(int i=0;i<n;++i){
    ll w,p;
    cin >> w >> p;
    for(int j=0;j<k;j++){
      dp[i+1][j+1] = max(dp[i][j],dp[i+1][j+1])

}

