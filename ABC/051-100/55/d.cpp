#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
    
  for(int k=0;k<2;k++){
    vector<vector<bool> > dp(n+1,vector<bool>(2,false));
    dp[0][k] = true;
    for(int i=0;i<n;i++){
      if(s[i] == 'o'){
        if(dp[i][0]) dp[i+1][0] = true;
        if(dp[i][1]) dp[i+1][1] = true;
      }
      else{
        if(dp[i][0] || dp[i][1] ) dp[i+1][1] = true;
      }
    }
    if(s[0] == 'o' && k==0 && dp[n][0]) cout << "Yes" << endl;
    else if(s[0] == 'o' && k==1 && (dp[n][0]||dp[n][1]))  
  return 0;
}

