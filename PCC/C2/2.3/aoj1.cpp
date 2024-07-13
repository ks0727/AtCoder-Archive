#include <iostream>
#include <vector>
using namespace std;

void chmax(int &a ,int b){
  a = max(a,b);
}

int main(){
  int n,w;
  cin >> n >> w;
  vector<vector<int> > dp(n+1,vector<int>(w+1));
  for(int i=0;i<n;++i){
    int vi,wi;
    cin >> vi >> wi;
    for(int j=0;j<=w;++j){
      if(j < wi) dp[i+1][j] = dp[i][j];
      else dp[i+1][j] = max(dp[i][j],dp[i][j-wi]+vi);
    }
  }
  cout << dp[n][w] << endl;
  return 0;
}

