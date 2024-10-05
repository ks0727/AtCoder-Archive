#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n),s(n+1);
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++) s[i+1] = s[i]^a[i];
  ll ans = 0;
  for(int k=0;k<32;k++){
    int ok = 0;
    int ng = 0;
    vector<ll> dp(n+1);
    dp[0] = 0;
    for(int i=0;i<n;i++){
      if(s[i]>>k&1){
         swap(ok,ng);
         dp[i+1] = dp[i]+ok;
      }else{
        dp[i+1] = dp[i]+ok;
      }
    }
    ans += (1LL<<k)*dp[n];
  }
  cout << ans << endl;
}



