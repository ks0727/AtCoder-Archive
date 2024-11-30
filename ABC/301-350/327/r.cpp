#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
  int n;
  cin >> n;
  const double INF = 1e18;
  vector<double> dp(n+1,-INF);
  dp[0] = 0;
  for(int i=0;i<n;i++){
    double p;
    cin >> p;
    vector<double> old = dp;
    swap(dp,old);
    for(int j=1;j<=n;j++){
      if(old[j-1] == -INF) continue;
      if(j-1 >= 0) dp[j] = max(old[j-1]*0.9+p,dp[j]);
    }
  }
  double ans = -INF;
  vector<double> ns(n+1,0);
  double now = 1;
  double sum = 0;
  for(int i=0;i<=n;i++){
    ns[i] = now + sum;
    sum += now;
    now = now*0.9;
  }

  for(int i=1;i<=n;i++){
    double r = dp[i]/ns[i-1] - 1200 / (double)sqrt(i);
    ans = max(ans,r);
  }
  printf("%.10f\n",ans);
}

    





  
