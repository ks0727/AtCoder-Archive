#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[4001][4001];

void chmax(int &a, int b){a = max(a,b);}

int main(){
  string s,t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i] == t[j]){
        chmax(dp[i+1][j+1],dp[i][j]+1);
        ans = max(ans,dp[i+1][j+1]);
      }
    }
  }
  
  cout << ans << endl;
  return 0;
}

