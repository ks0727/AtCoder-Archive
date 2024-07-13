#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

mint dp[10001][101][2];

int main(){
  int d;
  cin >> d;
  string n;
  cin >> n;
  for(int i=0;i<=n.size();++i)for(int j=0;j<=d;++j)for(int k=0;k<2;k++) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  for(int i=0;i<n.size();i++){
    int num = n[i]-'0';
    for(int j=0;j<d;++j){
         for(int l=0;l<10;++l){
           if(l < num){
             dp[i+1][(j+l)%d][1] += dp[i][j][0];
           }
           else if(l == num){
             dp[i+1][(j+l)%d][0] += dp[i][j][0];
           }
          dp[i+1][(j+l)%d][1] += dp[i][j][1];
        }
    }
  }
  mint ans = dp[n.size()][0][0] + dp[n.size()][0][1]-1;
  cout << ans.val()<< endl;
  return 0;
}

