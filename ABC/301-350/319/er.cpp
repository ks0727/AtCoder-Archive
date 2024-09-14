#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main(){
  int n; ll x,y;
  cin >> n >> x >> y;
  vector<ll> p(n-1),t(n-1);
  for(int i=0;i<n-1;i++) cin >> p[i] >> t[i];
  ll lc = 1;
  for(int i=0;i<n-1;i++) lc = lcm(p[i],lc);
  vector<ll> d(lc);
  for(int j=0;j<lc;j++){
     ll now = j;
     ll els = 0;
     for(int i=0;i<n-1;i++){
       ll k = (now+p[i]-1)/p[i];
       els += p[i]*k - now;
       els += t[i];
       now = p[i]*k+t[i];
     }
      d[j] = els;
   }
  int Q;
  cin >> Q;
  while(Q--){
    ll q;
    cin >>q;
    ll ans = 0;
    q+=x;
    ll r = q%lc;   
    ans += d[r]+q+y;
    cout << ans << '\n';
  } 

  return 0;
}

