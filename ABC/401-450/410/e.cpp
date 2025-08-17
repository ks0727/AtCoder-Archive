#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,h,m;
  cin >> n >> h >> m;
  vector<vector<int> > dp(n+1,vector<int>(h+1,-1));
  dp[0][h] = m;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    for(int j=h;j>=0;j--){
      dp[i+1][j] = max(dp[i+1][j],dp[i][j]-b);
      if(j-a >= 0) dp[i+1][j-a] = max(dp[i][j],dp[i+1][j-a]);
    }
  }
  
  for(int i=n;i>=0;i--){
    for(int j=0;j<=h;j++){
      if(dp[i][j] >= 0){
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}

