#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  const int INF = 1e9;
  vector<int> dp(n,INF);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    int id = lower_bound(dp.begin(),dp.end(),x) - dp.begin();
    dp[id] = x;
  }
  int lis = 0;
  for(int i=n-1;i>=0;i--) if(dp[i] != INF){
    lis = i+1;
    break;
  } 
  cout << n - lis << endl;
  return 0;
}

