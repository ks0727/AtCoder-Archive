#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> c(n),p(n);
  vector<vector<int> > a(n);
  for(int i=0;i<n;i++){
    cin >> c[i] >> p[i];
    a[i].resize(p[i]);
    for(int j=0;j<p[i];j++) cin >> a[i][j];
  }
  vector<double> dp(m+1);
  for(int r=1;r<=m;r++){
    for(int i=0;i<n;i++){
      double now = 0;
      double b = 0;
      for(int d : a[i]){
        if(d > 0)  now += dp[max(0,r-d)];
        else b+=1;
      }
      now /= p[i] b /= p[i];
      now += c[i]; now /= (1-b);
      dp[r] = min(dp[r],now);
    }
  }
  printf("%.10f\n",dp[m]);
  return 0;
}

