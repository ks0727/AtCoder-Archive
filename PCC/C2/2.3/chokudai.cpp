#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  const int INF = 1e9;
  vector dp(n+1,INF);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    int id = lower_bound(dp.begin(),dp.end(),x) -dp.begin();
    dp[id] = x;
  }
  for(int i=n;i>=0;i--){
    if(dp[i] != INF){
      cout << i+1 << endl;
      return 0;
    }
  }
  return 0;
}

