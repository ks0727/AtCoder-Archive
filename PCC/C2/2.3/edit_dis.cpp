#include <iostream>
using namespace std;

int dp[1001][1001];

int main(){
  string s,t;
  cin >> s >> t;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<t.size();j++){
      if(s[i+1] == t[j+1]){
        dp[i+1][j+1] = max(dp[i][j]+1,max(dp[i][j+1],dp[i+1][j]));
      }else{
        dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
      }
    }
  }
  int ll = max(s.size(),t.size());
  cout <<  dp[s.size()][t.size()] << endl;
  return 0;
}

