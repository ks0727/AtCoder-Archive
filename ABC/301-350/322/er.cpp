#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int n,k,p;
int c[2<<17];
int a[100][6];
int main(){
  cin >> n >> k >> p;
  for(int i=0;i<n;i++){
    cin >> c[i];
    for(int j=0;j<k;j++) cin >> a[i][j];
  }
  map<vector<int>,ll> dp;
  dp[vector<int>(k)] = 0;
  for(int i=0;i<n;++i)
  {
    map<vector<int>,ll> old=dp;
    for(auto [arr,cost] : old)
    {
      vector<int> arr2 = arr;
      for(int j=0;j<k;++j)
      {
        arr2[j] = min(arr[j]+a[i][j],p);
      }
      if(dp.count(arr2)){
        dp[arr2] = min(cost+c[i],dp[arr2]);
      }else{
        dp[arr2] = cost + c[i];
      }
   }
  }
  const ll INF = 1e18;
  ll ans = INF;
  if(dp.count(vector<int>(k,p))) ans = dp[vector<int>(k,p)];
  else ans = -1;
  cout << ans << endl;
  return 0;
}

