#include <iostream>
#include <vector>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--)
  {
    long long a,s;
    cin >> a >> s;
    vector dp(62,vector<bool>(2));
    dp[0][0] = true;
    for(int i=0;i<61;i++)
    {
      if(a>>i&1 && s>>i&1) //(x,y) = (1,1) かつ1である必要がある
      {
        if(dp[i][1]) dp[i+1][1] = true;
        if(!dp[i+1][0]) dp[i+1][0] = false;
      }else if(a>>i&1 && ~(s>>i&1)) //(x,y)=(1,1)かつ0である必要がある
      {
        if(dp[i][0]) dp[i+1][1] = true;
        if(!dp[i+1][0]) dp[i+1][0] = false;
      }else if(~(a>>i&1) && s>>i&1) //(x,y)=(1,1)ではなく, 1である必要がある
      {
        if(dp[i][1]) dp[i+1][0] = true;
        if(dp[i][0]) dp[i+1][0] = true;
        if(!dp[i+1][1]) dp[i+1][1] = false; 
      }else //(x,y)=(1,1)ではなく, 0である必要がある
      {
        if(dp[i][0]) dp[i+1][0] = true;
        if(dp[i][1]) dp[i+1][1] = true;
      }
    }
    //for(int i=0;i<61;i++)
    {
     // for(int j=0;j<2;j++) cout << dp[i][j] << ' '; cout << endl;
    }
    if(dp[61][0]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

