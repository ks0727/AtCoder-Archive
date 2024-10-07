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
    vector<ll> dp(n+1);
    dp[0] = 0;
    int zeros = 0;
    int odd = -1;
    int even = -1;
    bool  ise  = false;
    bool ok = false;
    for(int i=0;i<n;i++){
      if(a[i]>>k&1){
        if(ise){ //今の値が奇数番目
          ok = true;
           dp[i+1] = even+1+zeros;
           ise = false;
           even = dp[i+1];
           zeros = 0;
        }else{
          ok = true;
          dp[i+1] = odd+1+zeros;
          ise = true;
          odd = dp[i+1];
          zeros = 0;
        }
      }else{
        if(i!=0 && a[i-1]>>k&1)  dp[i+1] = dp[i]+1;
        else if(i!=0 && ~(a[i-1]>>k&1)) dp[i+1] = dp[i];
        else dp[i+1] = 0;
        zeros++;
      }
    }
    ll now = 0;
    for(int i=1;i<=n;i++) now += dp[i];
    ans += (1LL<<k)*now; 
  }
  cout << ans << endl;
}



