#include <iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<vector<double> > dp(n+1,vector<double>(2));
  // 1 : 前に使っている 0: 前に使っていない
  for(int i=0;i<n;i++){
    dp[i+1][0] = dp[i][1];
    dp[i+1][1] = max((dp[i][0]+double(a[i]))
