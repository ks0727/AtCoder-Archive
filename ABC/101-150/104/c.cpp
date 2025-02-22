#include <iostream>
#include<cassert>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int d,g;
  cin >> d >> g;
  vector<long long> p(d),c(d);
  for(int i=0;i<d;i++) cin >> p[i] >> c[i];
  vector dp(101,vector<long long>(1001));
  int ans = 1001001001;
  for(int i=0;i<d;i++){
    for(int j=0;j<p[i];j++){
      for(int k=0;k<1001;k++){
        dp[j+1][k+1] = max(dp[j][k]+100*(i+1),dp[j+1][k+1]);
        if(j == p[i]-1) dp[j+1][k+1] += c[i];
        if(dp[j+1][k+1] >= g){
          ans = min(ans,k);
          break;
        }
      }
    }
  }
  cout << ans << endl;
}

