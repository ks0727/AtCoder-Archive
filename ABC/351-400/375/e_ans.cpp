#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void chmin(int &a, int b){
  a = min(a,b);
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i] >> b[i];
  int x = 0; //sum
  for(i=0;i<n;i++) x += b[i];
  if(x%3 ! = 0)
  {
    cout << -1 << endl;
    return 0;
  }
  x /= 3;
  const int INF = 1001001001;
  vector dp(x+1,vector<int>(x+1,INF));
  dp[0][0] = 0;
  for(int i=0;i<n;i++)
  {
    vector old(x+1,vector<int>(xx+1,INF));
    swap(dp,old);
    int cost1 = a[i] != 1;
    int cost2 = a[i] != 2;
    int cost3 = a[i] != 3;
    for(int j1=0;j1<x+1;j1++)for(int j2=0;j2<x+1;j2++){
      if(j1+b[i]<=x) chmin(dp[j1+b[i]][j2],old[j1][j2]+cost1);
      if(j2+b[i]<=x) chmin(dp[j1][j2+b[i]],old[j1][j2]+cost2);
      chmin(dp[j1][j2],old[j1][j2]+cost3);
  }
  int ans = dp[x][x];
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}

