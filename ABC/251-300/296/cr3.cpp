#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main(){
  ll n,m; cin >> n >> m;
  ll ans = 1e18;
  for(ll i=1;i<(n+1);i++){
    if(i*i == m){
      cout <<(ll)i*i << endl;
      return 0;
    }
    if(i*i > m) break;
    if(m % i == 0){
      ll x = m/i;
      if(x <= n && x*i >= m){
        cout << x << endl;
        return 0;
      }
    }else{
      ll x = m/i + 1;
      if(x > n) continue;
      ll y = x*i;
      if(y >= m && ans-m > y-m){
        ans = y;
      }
    } 
  }
  if(ans != 1e18) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
