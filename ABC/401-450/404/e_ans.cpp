#include <iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int solve(vector<int> c){
  int n = c.size();
  const int INF = 1001001001;
  vector<int> dp(n+1,INF);
  dp[0] = 0;
  for(int i=0;i<n;i++){
    int now = INF;
    for(int j=0;j<c[i];j++){
      if(i-j>=0) now = min(now,dp[i-j]+1);
    }
    dp[i+1] = now+1;
  }
  return dp[n];
}
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  vector<int> a(n);
  for(int i=0;i<n-1;i++) cin >> c[i+1];
  for(int i=0;i<n-1;i++) cin >> a[i+1];
  a[0] = 1;
  vector<int> nc;
  int ans = 0;
  for(int i=1;i<n;i++){
    nc.push_back(c[i]);
    if(a[i]){
      ans += solve(nc);
      nc = vector<int>();
    }
  }
  cout << ans << endl;
  return 0;
}

