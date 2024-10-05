#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void chmax(ll &a, ll b) {
  a = max(a,b);
};

int main(){
  int n;
  cin >> n;
  vector a(2*n,vector<ll>(2*n));
  for(int i=0;i<2*n-1;i++)
  {
    for(int j=0;j<2*n-i-1;j++){
      ll x;
      cin >> x;
      a[i][j]= x;
    }
  }
  int n2 = 1<<(2*n+1);
  vector<ll> dp(n2);
  for(int i=0;i<n2;i++){
    for(int j=0;j<n*2;j++){
      for(int k=j+1;k<2*n;k++){
        if(k==j) continue;
        if(i&1<<j) continue;
        if(i&1<<k) continue;
        chmax(dp[i|1<<j|1<<k],dp[i]^a[j][k-j-1]);
      }
    }
  }
  long long ans = 0;
  for(int i=0;i<n2;i++) ans = max(ans,dp[i]);
  cout << ans << endl;
  return 0;
}

