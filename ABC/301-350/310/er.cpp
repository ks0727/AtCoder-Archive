#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  vector dp(n+1,vector<long long>(2));
  for(int i=0;i<n;i++){
    if(s[i] == '1'){
      dp[i+1][1]++;
      dp[i+1][0] += dp[i][1];
      dp[i+1][1] += dp[i][0];
    }else{
      dp[i+1][0]++;
      dp[i+1][1] += dp[i][0];
      dp[i+1][1] += dp[i][1];
    }
    ans += dp[i+1][1];
  }
  cout << ans << endl;
  return 0;
}

